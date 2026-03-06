
# Minishell Requirements

## 日本語

---

## 1. プロジェクト概要

* **目標**: シンプルな Bash 風シェルを実装する
* **学習ポイント**: プロセス、ファイルディスクリプタ、入出力リダイレクト、パイプライン、シグナル処理
* **出典:** 42 School minishell(version 7.1)

---

## 2. 環境とルール
* C 言語で作成
* 異常終了（セグフォルト、ダブルフリーなど）禁止
* メモリリーク禁止（`readline()` によるリークは例外）
* Makefile 必須ルール:
  `$(NAME)`, `all`, `clean`, `fclean`, `re`
* コンパイルオプション: `-Wall -Wextra -Werror`
* libft 使用時はソースを含め、Makefile でビルド

---

## 3. 必須パート

### プログラム情報
* **名前**: `minishell`
* **提出ファイル**: `Makefile`, `*.h`, `*.c`
* **許可される外部関数**:

  ```
  readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay,
  add_history, printf, malloc, free, write, access, open, read, close,
  fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset,
  kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2,
  pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname,
  ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum,
  tgetstr, tgoto, tputs
  ```

### 機能要件

1. **プロンプト表示**
   * コマンド入力待機時にプロンプトを表示
   * コマンド履歴を保存（history 対応）

2. **コマンド実行**
   * PATH を基に実行ファイルを探索して実行
   * 絶対パス/相対パス実行をサポート

3. **グローバル変数**
   * グローバル変数の使用禁止（ただし、シグナル番号保存用途で **1個のみ** 許可）
   * グローバル変数がデータ構造へのアクセスや他情報の提供をしてはならない

4. **文字列処理**
   * 閉じられていない引用符や要求されていない特殊文字（`\`, `;`）は解釈しない
   * **'（シングルクォート）**: 内部メタ文字を解釈しない
   * **"（ダブルクォート）**: `$` 以外のメタ文字を解釈しない

5. **リダイレクト**
   * `<` : 入力リダイレクト
   * `>` : 出力リダイレクト（上書き）
   * `>>` : 出力リダイレクト（追記）
   * `<<` : heredoc（指定 delimiter まで入力、history 更新なし）

6. **パイプ**
   * `|` でつながれたコマンドの出力を次のコマンド入力へ接続

7. **環境変数**
   * `$VAR` : 環境変数値へ展開
   * `$?` : 直前の foreground コマンド終了ステータスへ展開

8. **シグナル処理（bash と同様）**
   * ctrl-C : 新しいプロンプトを表示
   * ctrl-D : シェル終了
   * ctrl-\ : 無視（何もしない）

9. **組み込みコマンド（Builtins）**
   * `echo`（`-n` オプション対応）
   * `cd`（絶対/相対パスのみ）
   * `pwd`
   * `export`（オプションなし）
   * `unset`（オプションなし）
   * `env`（オプション/引数なし）
   * `exit`（オプションなし）

---

## English

---

## 1. Project Overview

* **Goal**: Implement a simple Bash-like shell
* **Learning points**: process control, file descriptors, I/O redirection, pipelines, signal handling
* **Source:** 42 School minishell(version 7.1)

---

## 2. Environment and Rules
* Must be written in C
* No unexpected termination (segfault, double free, etc.)
* No memory leaks (`readline()` leaks are accepted as an exception)
* Required Makefile rules:
  `$(NAME)`, `all`, `clean`, `fclean`, `re`
* Compile flags: `-Wall -Wextra -Werror`
* If using libft, include sources and build through Makefile

---

## 3. Mandatory Part

### Program Info
* **Name**: `minishell`
* **Submission files**: `Makefile`, `*.h`, `*.c`
* **Allowed external functions**:

  ```
  readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay,
  add_history, printf, malloc, free, write, access, open, read, close,
  fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset,
  kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2,
  pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname,
  ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum,
  tgetstr, tgoto, tputs
  ```

### Functional Requirements

1. **Prompt display**
   * Show a prompt while waiting for command input
   * Store command history

2. **Command execution**
   * Search and execute binaries using PATH
   * Support absolute and relative path execution

3. **Global variable policy**
   * No global variables (except **one** global used only for signal number)
   * The global variable must not provide access to other data structures or extra information

4. **String handling**
   * Do not interpret unclosed quotes or unsupported special characters (`\`, `;`)
   * **' (single quote)**: disable meta-character interpretation inside
   * **" (double quote)**: disable meta-character interpretation except `$`

5. **Redirections**
   * `<` : input redirection
   * `>` : output redirection (truncate)
   * `>>` : output redirection (append)
   * `<<` : heredoc (read until delimiter, do not add to history)

6. **Pipes**
   * Connect output of one command to input of the next with `|`

7. **Environment variables**
   * `$VAR` : expand to environment variable value
   * `$?` : expand to exit status of the last foreground command

8. **Signal handling (same behavior as bash)**
   * ctrl-C : display a new prompt
   * ctrl-D : exit shell
   * ctrl-\ : ignore (no action)

9. **Builtins**
   * `echo` (supports `-n`)
   * `cd` (absolute/relative paths only)
   * `pwd`
   * `export` (no options)
   * `unset` (no options)
   * `env` (no options/arguments)
   * `exit` (no options)

---

## 한국어

---

## 1. 프로젝트 개요

* **목표**: 간단한 bash와 유사한 셸 구현
* **학습 포인트**: 프로세스, 파일 디스크립터, 입출력 리다이렉션, 파이프라인, 시그널 처리
* **출처:** 42 School minishell(version 7.1)

---

## 2. 환경 및 규칙
* C 언어로 작성
* 예기치 않은 종료(세그폴트, 더블 프리 등) 금지
* 메모리 누수 금지 (`readline()`로 인한 누수는 예외)
* Makefile 필수 규칙:
  `$(NAME)`, `all`, `clean`, `fclean`, `re`
* 컴파일 옵션: `-Wall -Wextra -Werror`
* libft 사용 시 소스 포함 후 Makefile에서 빌드

---

## 3. 필수 파트

### 프로그램 정보
* **이름**: `minishell`
* **제출 파일**: `Makefile`, `*.h`, `*.c`
* **외부 함수 허용 목록**:

  ```
  readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay,
  add_history, printf, malloc, free, write, access, open, read, close,
  fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset,
  kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2,
  pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname,
  ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum,
  tgetstr, tgoto, tputs
  ```

### 기능 요구사항

1. **프롬프트 출력**
   * 명령어 입력 대기 시 프롬프트 표시
   * 명령어 실행 내역 저장 (history 지원)

2. **명령 실행**
   * PATH를 기반으로 실행 파일 탐색 후 실행
   * 절대경로/상대경로 실행 지원

3. **글로벌 변수**
   * 전역 변수 사용 금지 (단, **1개만** 시그널 번호 저장 용도로 허용)
   * 전역 변수가 데이터 구조에 접근하거나 다른 정보를 제공하면 안 됨

4. **문자열 처리**
   * 닫히지 않은 인용부호나 요구되지 않은 특수문자(`\`, `;`) 미해석
   * **' (싱글쿼트)**: 안의 메타문자 해석 금지
   * **" (더블쿼트)**: `$` 제외 모든 메타문자 해석 금지

5. **리다이렉션**
   * `<` : 입력 리다이렉션
   * `>` : 출력 리다이렉션 (덮어쓰기)
   * `>>` : 출력 리다이렉션 (추가모드)
   * `<<` : heredoc (지정된 delimiter까지 입력 받음, history 갱신 X)

6. **파이프**
   * `|` 로 연결된 명령들의 출력을 다음 명령의 입력으로 연결

7. **환경변수**
   * `$VAR` : 환경변수 값으로 치환
   * `$?` : 마지막 실행한 foreground 명령의 종료 상태로 치환

8. **시그널 처리 (bash와 동일하게)**
   * ctrl-C : 새 프롬프트 표시
   * ctrl-D : 셸 종료
   * ctrl-\ : 무시 (아무 동작 없음)

9. **내장 명령어 (Builtins)**
   * `echo` (-n 옵션 지원)
   * `cd` (절대/상대 경로만)
   * `pwd`
   * `export` (옵션 없이)
   * `unset` (옵션 없이)
   * `env` (옵션/인자 없이)
   * `exit` (옵션 없이)

---
