# CppTrace

<p>
    <img src="https://img.shields.io/github/v/release/ruiyangzhou01/CppTrace?&color=blue&logo=hack-the-box" />
    <img alt="C++" src="https://img.shields.io/badge/-C++-9f62a5?style=flat&logo=cplusplus&logoColor=white" />
</p>

[English](https://github.com/ruiyangzhou01/CppTrace/blob/main/README.md) | [简体中文](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_zh.md) | [Deutsch](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_de.md) | [Español](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_es.md) | [Français](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_fr.md)

CppTrace is a lightweight logging library for tracing C++ variables.

## Features

- Trace scalar variables in a file.
- Trace array variables in a file.
- Trace variables inside loops (with cycle counters).
- Attach descriptions to traces.
- Output includes the variable name, type, value, function scope, trace line number, cycle index, and description.

### Screenshot

![screenshot](README.assets/screenshot.png)

## Install

1. Go to the [GitHub releases page](https://github.com/ruiyangzhou01/CppTrace/releases).
2. Expand `Assets` and download the `CppTrace.h` header file.
3. Include the header file in your project.

## Usage

The library provides two main APIs:

```cpp
trace(varName, [cycleVariables], [description]);
traceArr(varName, [cycleVariables], [description]);
```

First include the header file in your project with `#include "CppTrace.h"`, then call the two functions in your program. They print the variable information to the console, including the variable name, type, value, function scope, trace line number, cycle index, and description.

## Todo

- Support output to a file
- Provide APIs to simplify secondary development

## License

[GPL-3.0 License](https://github.com/ruiyangzhou01/CppTrace/blob/main/LICENSE) © ruiyangzhou01
