#!/usr/bin/env bash

set -u

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$SCRIPT_DIR"
while [[ "$PROJECT_ROOT" != "/" ]]; do
	if [[ -f "$PROJECT_ROOT/Makefile" && -d "$PROJECT_ROOT/srcs" ]]; then
		break
	fi
	PROJECT_ROOT="$(dirname "$PROJECT_ROOT")"
done

if [[ "$PROJECT_ROOT" == "/" ]]; then
	echo "[ERROR] project root not found."
	exit 1
fi

cd "$PROJECT_ROOT" || exit 1

MS_BIN="$PROJECT_ROOT/minishell"
BASH_BIN="bash --noprofile --norc"

TMP_DIR="$(mktemp -d)"
cleanup() {
	rm -rf "$TMP_DIR"
}
trap cleanup EXIT

strip_output() {
	sed -E $'s/\x1B\[[0-9;]*[[:alpha:]]//g' \
	| sed 's/minishell ❯ //g' \
	| sed $'s/\r//g' \
	| sed '/^[[:space:]]*$/d' \
	| sed '/^exit$/d'
}

remove_input_echo() {
	local script_content="$1"
	local clean_file="$2"
	local commands_file="$TMP_DIR/commands.$$"
	local filtered_file="$TMP_DIR/filtered.$$"

	printf "%s\n" "$script_content" | sed '/^[[:space:]]*$/d' >"$commands_file"
	grep -Fvx -f "$commands_file" "$clean_file" >"$filtered_file" || true
	mv "$filtered_file" "$clean_file"
	rm -f "$commands_file"
}

run_shell_script() {
	local shell_kind="$1"
	local script_content="$2"
	local output_prefix="$3"
	local raw_file="$TMP_DIR/${output_prefix}.raw"
	local clean_file="$TMP_DIR/${output_prefix}.clean"
	local status_file="$TMP_DIR/${output_prefix}.status"

	if [[ "$shell_kind" == "minishell" ]]; then
		printf "%s\n" "$script_content" | "$MS_BIN" >"$raw_file" 2>&1
	else
		printf "%s\n" "$script_content" | bash --noprofile --norc >"$raw_file" 2>&1
	fi
	echo $? >"$status_file"
	strip_output <"$raw_file" >"$clean_file"
	if [[ "$shell_kind" == "minishell" ]]; then
		remove_input_echo "$script_content" "$clean_file"
	fi
}

print_diff() {
	local expected_file="$1"
	local actual_file="$2"
	if command -v diff >/dev/null 2>&1; then
		diff -u "$expected_file" "$actual_file" || true
	else
		echo "Expected output:"
		cat "$expected_file"
		echo "Actual output:"
		cat "$actual_file"
	fi
}

run_case() {
	local case_id="$1"
	local case_name="$2"
	local case_script="$3"
	local bash_prefix="bash_${case_id}"
	local mini_prefix="mini_${case_id}"
	local bash_clean="$TMP_DIR/${bash_prefix}.clean"
	local mini_clean="$TMP_DIR/${mini_prefix}.clean"
	local bash_status="$TMP_DIR/${bash_prefix}.status"
	local mini_status="$TMP_DIR/${mini_prefix}.status"

	run_shell_script "bash" "$case_script" "$bash_prefix"
	run_shell_script "minishell" "$case_script" "$mini_prefix"

	if cmp -s "$bash_clean" "$mini_clean" && cmp -s "$bash_status" "$mini_status"; then
		echo "[PASS] $case_name"
		return 0
	fi

	echo "[FAIL] $case_name"
	echo "- Exit status (bash): $(cat "$bash_status")"
	echo "- Exit status (minishell): $(cat "$mini_status")"
	echo "- Output diff:"
	print_diff "$bash_clean" "$mini_clean"
	return 1
}

if [[ ! -x "$MS_BIN" ]]; then
	echo "[INFO] minishell binary not found. Running make..."
	if ! make -C "$PROJECT_ROOT"; then
		echo "[ERROR] build failed."
		exit 1
	fi
fi

TEST_FILE="$TMP_DIR/minishell_quick_test.txt"

pass_count=0
fail_count=0

if run_case "01" "Basic echo" $'echo hello world\nexit'; then
	pass_count=$((pass_count + 1))
else
	fail_count=$((fail_count + 1))
fi

if run_case "02" "Environment expansion" $'export QUICK_TEST_VAR=42\necho $QUICK_TEST_VAR\nexit'; then
	pass_count=$((pass_count + 1))
else
	fail_count=$((fail_count + 1))
fi

if run_case "03" "Pipeline" $'echo minishell | cat\nexit'; then
	pass_count=$((pass_count + 1))
else
	fail_count=$((fail_count + 1))
fi

printf -v script04 'echo file_line > "%s"\ncat "%s"\nexit' "$TEST_FILE" "$TEST_FILE"
if run_case "04" "Output redirection" "$script04"; then
	pass_count=$((pass_count + 1))
else
	fail_count=$((fail_count + 1))
fi

printf -v script05 'echo first > "%s"\necho second >> "%s"\ncat "%s"\nexit' "$TEST_FILE" "$TEST_FILE" "$TEST_FILE"
if run_case "05" "Append redirection" "$script05"; then
	pass_count=$((pass_count + 1))
else
	fail_count=$((fail_count + 1))
fi

printf -v script06 'echo input_ok > "%s"\ncat < "%s"\nexit' "$TEST_FILE" "$TEST_FILE"
if run_case "06" "Input redirection" "$script06"; then
	pass_count=$((pass_count + 1))
else
	fail_count=$((fail_count + 1))
fi

echo
echo "Quick test summary: PASS=$pass_count FAIL=$fail_count"

if [[ "$fail_count" -eq 0 ]]; then
	echo "All quick tests passed."
	exit 0
fi

echo "Some quick tests failed."
exit 1
