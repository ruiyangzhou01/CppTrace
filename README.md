# CppTrace

<p>
    <img src="https://img.shields.io/github/v/release/ruiyangzhou01/CppTrace?&color=blue&logo=hack-the-box)" />
    <img alt="C++" src="https://img.shields.io/badge/-C++-9f62a5?style=flat&logo=cplusplus&logoColor=white" />
</p>

[English Readme](https://github.com/ruiyangzhou01/CppTrace/blob/main/README.md) | [中文自述文件](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_zh.md)

A logging library to trace C++ variables.

## Features

- Trace simple variable among the file.
- Trace array variable among the file.
- Trace variable in the cycle.
- Add description with variable.
- Information including variable name, variable type, value, function container, the line of the trace code, cycle number, and the description.

### Screenshot

![screenshoot](README.assets/screenshot.png)

## Install

[GitHub releases page](https://github.com/ruiyangzhou01/CppTrace/releases), click on `Assets` at the bottom to show the files available in the release and then click on the head file you want to download. Finally, include the head file in your project.

## Usage

The library now has two main API:

```
trace(varName, [a list including cycle variables], [a string of the description])
traceArr(varName, [a list including cycle variables], [a string of the description])
```

First include the head file in your project by `#include "CppTrace.h"`, and then call the two function in the program, it can print the variable's information to command window, including variable name, variable type, value, function container, the line of the trace code, cycle number, and the description.

## Todo

- Support function that can print to file
- Provide API for develop secondary easier

## License

[GPL-3.0 License](https://github.com/ruiyangzhou01/CppTrace/blob/main/LICENSE) © ruiyangzhou01
