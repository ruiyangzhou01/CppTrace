# CppTrace

<p>
    <img src="https://img.shields.io/github/v/release/ruiyangzhou01/CppTrace?&color=blue&logo=hack-the-box" />
    <img alt="C++" src="https://img.shields.io/badge/-C++-9f62a5?style=flat&logo=cplusplus&logoColor=white" />
</p>

[English](https://github.com/ruiyangzhou01/CppTrace/blob/main/README.md) | [简体中文](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_zh.md) | [Deutsch](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_de.md) | [Español](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_es.md) | [Français](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_fr.md)

CppTrace 是一个轻量级日志库，用于跟踪 C++ 变量。

## 功能

- 在文件中跟踪标量变量。
- 在文件中跟踪数组变量。
- 在循环中跟踪变量（包含循环计数器）。
- 为追踪记录添加说明。
- 输出信息包括变量名称、类型、值、所在函数、代码行号、循环序号以及说明。

### 屏幕截图

![screenshot](README.assets/screenshot.png)

## 安装

1. 前往 [GitHub 发布页面](https://github.com/ruiyangzhou01/CppTrace/releases)。
2. 展开 `Assets` 并下载 `CppTrace.h` 头文件。
3. 在您的项目中包含该头文件。

## 用法

该库提供两个主要接口：

```cpp
trace(varName, [cycleVariables], [description]);
traceArr(varName, [cycleVariables], [description]);
```

首先通过 `#include "CppTrace.h"` 在您的项目中包含头文件，然后在程序中调用这两个函数。它们会将变量信息打印到控制台，包括变量名称、类型、值、所在函数、代码行号、循环序号和说明。

## 待办事项

- 支持打印到文件的功能
- 为二次开发提供 API

## 开源许可证

[GPL-3.0 License](https://github.com/ruiyangzhou01/CppTrace/blob/main/LICENSE) © ruiyangzhou01
