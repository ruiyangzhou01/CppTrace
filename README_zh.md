# CppTrace

<p>
    <img src="https://img.shields.io/github/v/release/ruiyangzhou01/CppTrace?&color=blue&logo=hack-the-box" />
    <img alt="C++" src="https://img.shields.io/badge/-C++-9f62a5?style=flat&logo=cplusplus&logoColor=white" />
</p>

[English](https://github.com/ruiyangzhou01/CppTrace/blob/main/README.md) | [简体中文](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_zh.md) | [Deutsch](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_de.md) | [Español](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_es.md) | [Français](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_fr.md) | [日本語](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_ja.md)

CppTrace 是一个单头文件的 C++14 追踪辅助工具，会将变量信息打印到标准输出。它只包含一个头文件（`CppTrace.h`），并提供将输出重定向到日志文件的辅助函数。

## 功能

- 单头文件库（仅 `CppTrace.h`）。
- 使用 `trace` 追踪标量变量。
- 使用 `traceArr` 追踪固定大小数组。
- 可选的循环计数器（`std::list<int>`）。
- 每条追踪记录可附带说明。
- 输出信息包含变量名、`typeid(...).name()`、值、函数作用域、行号、循环计数以及说明。
- 提供将 `stdout` 重定向到文件的辅助函数（`InRedirect2File`、`OutRedirect2File`）。

### 屏幕截图

![screenshot](README.assets/screenshot.png)

## 环境要求与限制

- 需要 C++14 编译器。
- 默认仅支持 Windows，因为 `CppTrace.h` 包含 `<windows.h>` 并使用 `GetLocalTime`。
- `traceArr` 仅支持固定大小数组（不支持指针或 STL 容器）。它通过扫描 `\0` 判断已使用长度，因此数组应进行零初始化或以空字符结尾。
- 类型名称来自 `typeid(...).name()`，不同编译器输出可能不同（未做解码）。

## 安装

1. 前往 [GitHub 发布页面](https://github.com/ruiyangzhou01/CppTrace/releases)。
2. 展开 `Assets` 并下载 `CppTrace.h` 头文件。
3. 在项目中包含该头文件。

## 构建示例程序

仓库包含 `main.cpp` 作为示例。Windows 上可以使用 CMake 构建：

```bash
cmake -S . -B build
cmake --build build
```

## 用法

引入头文件并使用追踪宏：

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

可选参数 `cycleVariables` 是 `std::list<int>`（通常为循环下标）。如果只需要说明，请先传入空列表（`{}`）。

### 输出格式

标量追踪：

```text
TRACE [Var=int_var] [Type=i] [Value=3] [Fun=main, Line=16, Cycle=(1 2)] [Desc: This is the description]
```

数组追踪：

```text
TRACE [Array=int_arr] [Type=i, Len=4/60] [Array={2, 5, 4, 9}] [Fun=main, Line=27]
```

## 重定向输出到文件

两个辅助函数都使用 `freopen` 重定向 `stdout`，因此会影响之后的所有控制台输出：

```cpp
OutRedirect2File("Time");    // 使用类似 "2026-02-10 13-05-02.log" 的时间戳
OutRedirect2File("trace");   // 写入 "trace.log"
InRedirect2File("main.in");  // 将 stdout 重定向到 "main.in"
```

## 开源许可证

[GPL-3.0 License](https://github.com/ruiyangzhou01/CppTrace/blob/main/LICENSE) © ruiyangzhou01
