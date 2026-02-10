# CppTrace

<p>
    <img src="https://img.shields.io/github/v/release/ruiyangzhou01/CppTrace?&color=blue&logo=hack-the-box" />
    <img alt="C++" src="https://img.shields.io/badge/-C++-9f62a5?style=flat&logo=cplusplus&logoColor=white" />
</p>

[English](https://github.com/ruiyangzhou01/CppTrace/blob/main/README.md) | [简体中文](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_zh.md) | [Deutsch](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_de.md) | [Español](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_es.md) | [Français](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_fr.md) | [日本語](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_ja.md)

CppTrace is a single-header C++14 tracing helper that prints variable information to standard output. It ships as one header file (`CppTrace.h`) and includes helper functions for redirecting output to a log file.

## Features

- Single-header library (just `CppTrace.h`).
- Trace scalar variables with `trace`.
- Trace fixed-size arrays with `traceArr`.
- Optional cycle counters for nested loops (`std::list<int>`).
- Optional descriptions for each trace.
- Output includes variable name, `typeid(...).name()`, value(s), function scope, line number, cycle indices, and description.
- Helpers to redirect `stdout` to a file (`InRedirect2File`, `OutRedirect2File`).

### Screenshot

![screenshot](README.assets/screenshot.png)

## Requirements and limitations

- C++14 compiler.
- Windows-only out of the box because `CppTrace.h` includes `<windows.h>` and uses `GetLocalTime`.
- `traceArr` accepts fixed-size arrays only (not pointers or STL containers). It determines the used length by scanning for `\0`, so arrays should be zero-initialized or null-terminated.
- Type names come from `typeid(...).name()` and are compiler-specific (not demangled).

## Install

1. Go to the [GitHub releases page](https://github.com/ruiyangzhou01/CppTrace/releases).
2. Expand `Assets` and download the `CppTrace.h` header file.
3. Include the header file in your project.

## Build the demo

The repository includes `main.cpp` as a usage demo. On Windows, you can build it with CMake:

```bash
cmake -S . -B build
cmake --build build
```

## Usage

Include the header and use the tracing macros in your code:

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

The optional `cycleVariables` argument is a `std::list<int>` (typically loop indices). If you only want a description, pass an empty list (`{}`) first.

### Output format

Scalar traces:

```text
TRACE [Var=int_var] [Type=i] [Value=3] [Fun=main, Line=16, Cycle=(1 2)] [Desc: This is the description]
```

Array traces:

```text
TRACE [Array=int_arr] [Type=i, Len=4/60] [Array={2, 5, 4, 9}] [Fun=main, Line=27]
```

## Redirect output to a file

Both helpers redirect `stdout` using `freopen`, so they affect all subsequent console output:

```cpp
OutRedirect2File("Time");    // Uses a timestamp like "2026-02-10 13-05-02.log"
OutRedirect2File("trace");   // Writes to "trace.log"
InRedirect2File("main.in");  // Redirects stdout to "main.in"
```

## License

[GPL-3.0 License](https://github.com/ruiyangzhou01/CppTrace/blob/main/LICENSE) © ruiyangzhou01
