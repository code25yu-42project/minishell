# minishell

[日本語](#日本語) | [English](#english) | [한글](#한글)

---

## 日本語

42 minishell 課題向けの、シンプルな Bash 風シェルです。  
プロセス実行、パイプ/リダイレクト、環境変数展開、シグナル処理、基本 builtin コマンドを実装しています。

### 1) プロジェクト概要

- 実行ファイル: `minishell`
- 言語/ビルド: C / `-Wall -Wextra -Werror`
- 主な機能
	- プロンプト入力 + 履歴(`readline`)
	- コマンド実行(`PATH` 検索、絶対/相対パス実行)
	- リダイレクト(`<`, `>`, `>>`, `<<`)
	- パイプ(`|`)
	- 環境変数展開(`$VAR`, `$?`)
	- シグナル処理(`Ctrl-C`, `Ctrl-D`, `Ctrl-\`)
	- builtin: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`

### 2) ディレクトリ構成

```text
.
├── includes/         # 共通ヘッダ
├── libft/            # libft ライブラリ
├── srcs/
│   ├── minishell/    # メインループ、プロセス/シグナル/初期化
│   ├── parsing/      # トークナイズ、パース、展開
│   ├── execute/      # 実行、リダイレクト、heredoc、パイプライン
│   ├── builtin/      # builtin コマンド
│   ├── deque/        # 内部 deque ユーティリティ
│   ├── terminal/     # ターミナル関連ユーティリティ
│   ├── err/          # エラー出力
│   └── utils/        # 共通ユーティリティ
├── docs/
│   └── 00_requirements.md
├── Makefile
└── README.md
```

### 3) macOS 必須準備 (`readline`)

このプロジェクトでは `readline` のリンクが必要です。

#### 3-1. インストール

```bash
brew install readline
```

#### 3-2. インストールパス確認

```bash
brew --prefix readline
```

Apple Silicon(macOS arm64)では通常:

```text
/opt/homebrew/opt/readline
```

Intel macOSでは通常:

```text
/usr/local/opt/readline
```

#### 3-3. `Makefile` のパス処理

現在の `Makefile` は `readline` パスを自動検出します。

1) `brew --prefix readline` の結果を使用  
2) 失敗時は `/opt/homebrew/opt/readline` を確認  
3) さらに無ければ `/usr/local/opt/readline` を確認

通常は手動修正なしで `make` できます。  
必要であれば、以下のように明示指定も可能です。

```bash
make READLINE_PREFIX="$(brew --prefix readline)"
```

### 4) ビルド/実行

```bash
make
./minishell
```

クイックテスト:

```bash
./test/quick_test_minishell.sh
```

クリーン:

```bash
make clean
make fclean
make re
```

### 5) 使用例

```bash
echo hello
pwd
export TEST_VAR=42
echo $TEST_VAR
ls -al | grep minishell
cat < Makefile | head -n 20
echo append >> log.txt
```

### 6) トラブルシューティング

- `readline/readline.h` が見つからない場合:
	- `brew --prefix readline` を再確認
	- `make READLINE_PREFIX="$(brew --prefix readline)"` で明示指定してビルド
- リンクエラー(`-lreadline`)の場合:
	- `READLINE_PREFIX` が実際のインストール先と一致しているか確認
	- `make fclean && make` で再ビルド

### 7) 参考

- 要件整理: `docs/00_requirements.md`

---

## English

This is a simple Bash-like shell for the 42 minishell project.  
It implements process execution, pipes/redirections, environment expansion, signal handling, and core builtin commands.

### 1) Project Overview

- Executable: `minishell`
- Language/Build: C / `-Wall -Wextra -Werror`
- Core features
	- Prompt input + history (`readline`)
	- Command execution (`PATH` lookup, absolute/relative path)
	- Redirections (`<`, `>`, `>>`, `<<`)
	- Pipes (`|`)
	- Environment expansion (`$VAR`, `$?`)
	- Signal handling (`Ctrl-C`, `Ctrl-D`, `Ctrl-\`)
	- Builtins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`

### 2) Directory Structure

```text
.
├── includes/         # shared headers
├── libft/            # libft library
├── srcs/
│   ├── minishell/    # main loop, process/signal/init
│   ├── parsing/      # tokenizer, parser, expansion
│   ├── execute/      # executor, redirect, heredoc, pipeline
│   ├── builtin/      # builtin commands
│   ├── deque/        # internal deque utilities
│   ├── terminal/     # terminal helpers
│   ├── err/          # error output
│   └── utils/        # common utilities
├── docs/
│   └── 00_requirements.md
├── Makefile
└── README.md
```

### 3) Required macOS setup (`readline`)

This project needs proper `readline` linking.

#### 3-1. Install

```bash
brew install readline
```

#### 3-2. Check prefix

```bash
brew --prefix readline
```

Typical Apple Silicon(macOS arm64):

```text
/opt/homebrew/opt/readline
```

Typical Intel macOS:

```text
/usr/local/opt/readline
```

#### 3-3. `Makefile` path behavior

The current `Makefile` auto-detects the `readline` prefix:

1) use `brew --prefix readline`  
2) fallback to `/opt/homebrew/opt/readline`  
3) fallback to `/usr/local/opt/readline`

So in most cases, you can just run `make` without manual edits.  
You can still force a path like this:

```bash
make READLINE_PREFIX="$(brew --prefix readline)"
```

### 4) Build / Run

```bash
make
./minishell
```

Quick test:

```bash
./test/quick_test_minishell.sh
```

Clean targets:

```bash
make clean
make fclean
make re
```

### 5) Quick examples

```bash
echo hello
pwd
export TEST_VAR=42
echo $TEST_VAR
ls -al | grep minishell
cat < Makefile | head -n 20
echo append >> log.txt
```

### 6) Troubleshooting

- If `readline/readline.h` is missing:
	- re-check `brew --prefix readline`
	- build with `make READLINE_PREFIX="$(brew --prefix readline)"`
- If linker error (`-lreadline`) occurs:
	- verify `READLINE_PREFIX` points to the real install path
	- rebuild with `make fclean && make`

### 7) Reference

- Requirements summary: `docs/00_requirements.md`

---

## 한글

42 minishell 과제를 위한 간단한 Bash 유사 셸입니다.  
프로세스 실행, 파이프/리다이렉션, 환경변수 확장, 시그널 처리, 기본 builtin 명령어를 구현합니다.

### 1) 프로젝트 개요

- 실행 파일: `minishell`
- 언어/빌드: C / `-Wall -Wextra -Werror`
- 핵심 기능
	- 프롬프트 입력 + 히스토리(`readline`)
	- 명령 실행(`PATH` 검색, 절대/상대 경로 실행)
	- 리다이렉션(`<`, `>`, `>>`, `<<`)
	- 파이프(`|`)
	- 환경변수 확장(`$VAR`, `$?`)
	- 시그널 처리(`Ctrl-C`, `Ctrl-D`, `Ctrl-\`)
	- builtin: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`

### 2) 디렉토리 구조

```text
.
├── includes/         # 공용 헤더
├── libft/            # libft 라이브러리
├── srcs/
│   ├── minishell/    # 메인 루프, 프로세스/시그널/초기화
│   ├── parsing/      # 토크나이징, 파싱, 확장 처리
│   ├── execute/      # 실행기, 리다이렉션, heredoc, 파이프라인
│   ├── builtin/      # builtin 명령어
│   ├── deque/        # 내부 deque 유틸
│   ├── terminal/     # 터미널 관련 유틸
│   ├── err/          # 에러 출력
│   └── utils/        # 공용 유틸
├── docs/
│   └── 00_requirements.md
├── Makefile
└── README.md
```

### 3) macOS 필수 준비 (`readline`)

이 프로젝트는 `readline` 링크가 필요합니다.

#### 3-1. 설치

```bash
brew install readline
```

#### 3-2. 설치 경로 확인

```bash
brew --prefix readline
```

대부분 Apple Silicon(macOS arm64)은 아래 경로가 나옵니다.

```text
/opt/homebrew/opt/readline
```

Intel macOS에서는 보통 아래 경로입니다.

```text
/usr/local/opt/readline
```

#### 3-3. `Makefile` 경로 처리 방식

현재 `Makefile`은 `readline` 경로를 자동으로 감지합니다.

1) `brew --prefix readline` 결과 사용  
2) 실패 시 `/opt/homebrew/opt/readline` (Apple Silicon)  
3) 그마저 없으면 `/usr/local/opt/readline` (Intel) 확인

즉, 일반적으로 수동 수정 없이 바로 `make` 하면 됩니다.

필요하면 아래처럼 직접 경로를 지정해서 빌드할 수 있습니다.

```bash
make READLINE_PREFIX="$(brew --prefix readline)"
```

### 4) 빌드/실행

```bash
make
./minishell
```

빠른 테스트:

```bash
./test/quick_test_minishell.sh
```

정리:

```bash
make clean
make fclean
make re
```

### 5) 간단 사용 예시

```bash
echo hello
pwd
export TEST_VAR=42
echo $TEST_VAR
ls -al | grep minishell
cat < Makefile | head -n 20
echo append >> log.txt
```

### 6) 트러블슈팅

- `readline/readline.h`를 찾지 못하면:
	- `brew --prefix readline` 재확인
	- `make READLINE_PREFIX="$(brew --prefix readline)"`로 명시 지정 후 빌드
- 링크 에러(`-lreadline`)가 나면:
	- `READLINE_PREFIX` 경로가 실제 설치 경로와 일치하는지 확인
	- `make fclean && make`로 재빌드

### 7) 참고

- 요구사항 정리: `docs/00_requirements.md`
