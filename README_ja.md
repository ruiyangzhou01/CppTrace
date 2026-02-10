# CppTrace

<p>
    <img src="https://img.shields.io/github/v/release/ruiyangzhou01/CppTrace?&color=blue&logo=hack-the-box" />
    <img alt="C++" src="https://img.shields.io/badge/-C++-9f62a5?style=flat&logo=cplusplus&logoColor=white" />
</p>

[English](https://github.com/ruiyangzhou01/CppTrace/blob/main/README.md) | [简体中文](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_zh.md) | [Deutsch](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_de.md) | [Español](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_es.md) | [Français](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_fr.md) | [日本語](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_ja.md)

CppTrace は単一ヘッダーの C++14 トレースヘルパーで、変数情報を標準出力に出力します。`CppTrace.h` 1 ファイルで提供され、出力をログファイルへリダイレクトする補助関数も含まれます。

## 特長

- 単一ヘッダー（`CppTrace.h` のみ）。
- `trace` でスカラー変数を追跡。
- `traceArr` で固定長配列を追跡。
- ネストしたループ向けの任意のサイクルカウンタ（`std::list<int>`）。
- 各トレースに説明を付与可能。
- 出力には変数名、`typeid(...).name()`、値、関数スコープ、行番号、サイクルインデックス、説明が含まれます。
- `stdout` をファイルへリダイレクトする補助関数（`InRedirect2File`、`OutRedirect2File`）。

### スクリーンショット

![screenshot](README.assets/screenshot.png)

## 必要条件と制限

- C++14 コンパイラ。
- `CppTrace.h` が `<windows.h>` を含み `GetLocalTime` を使用するため、標準では Windows のみ対応。
- `traceArr` は固定長配列のみ対応（ポインタや STL コンテナは不可）。`\0` を探して使用長を決定するため、配列はゼロ初期化またはヌル終端が必要です。
- 型名は `typeid(...).name()` 由来で、コンパイラ依存（デマングルなし）。

## インストール

1. [GitHub Releases ページ](https://github.com/ruiyangzhou01/CppTrace/releases)へ移動します。
2. `Assets` を展開し、`CppTrace.h` をダウンロードします。
3. プロジェクトにヘッダーを追加します。

## デモのビルド

リポジトリには `main.cpp` のデモがあります。Windows で CMake を使う場合は次の通りです：

```bash
cmake -S . -B build
cmake --build build
```

## 使い方

ヘッダーをインクルードしてトレースマクロを使用します：

```cpp
#include "CppTrace.h"

int int_var = 3;
int int_arr[60] = {2, 5, 4, 9};

trace(int_var);
trace(int_var, {1, 2});
trace(int_var, {}, "This is the description");

traceArr(int_arr);
traceArr(int_arr, {1});
traceArr(int_arr, {1, 2}, "This is the description");
```

`cycleVariables` は `std::list<int>`（通常はループのインデックス）です。説明だけを付けたい場合は、最初に空のリスト（`{}`）を渡してください。

### 出力形式

スカラー変数のトレース：

```text
TRACE [Var=int_var] [Type=i] [Value=3] [Fun=main, Line=16, Cycle=(1 2)] [Desc: This is the description]
```

配列のトレース：

```text
TRACE [Array=int_arr] [Type=i, Len=4/60] [Array={2, 5, 4, 9}] [Fun=main, Line=27]
```

## 出力をファイルにリダイレクト

どちらのヘルパーも `freopen` で `stdout` をリダイレクトするため、以降の出力すべてに影響します：

```cpp
OutRedirect2File("Time");    // "2026-02-10 13-05-02.log" のようなタイムスタンプを使用
OutRedirect2File("trace");   // "trace.log" に出力
InRedirect2File("main.in");  // stdout を "main.in" にリダイレクト
```

## ライセンス

[GPL-3.0 License](https://github.com/ruiyangzhou01/CppTrace/blob/main/LICENSE) © ruiyangzhou01
