#ifndef CPPTRACE_H
#define CPPTRACE_H

/**
 * <h1>CppTrace</h1>
 * <p>A C++ head file designs to trace variable
 * <hr />
 * <h2>Usage</h2>
 * <p>Copy this .h file to your project directory, and include <b><code>#include "PowerTrace.h"</code></b> in your target .cpp file.
 * <h2>Copyright</h2>
 * @author      ruiyangzhou01
 * @repository      https://github.com/ruiyangzhou01/CppTrace
 * @License      GPL-3.0 License
 */

// TODO 可以考虑使用修饰符进行控制，如"N2D描述S"表示输出traceNum为2，description为描述，S表示储存为日志

#include <iostream>
#include <cstdio>
#include <list>
#include <ctime>
#include <windows.h>

using namespace std;

/**
 * <h2>Customize</h2>
 * <p>trace with customize setting
 */

// TODO 完善自定义内容
//#define varName(x) #x
//__FILE__
//__LINE__
//__FUNCTION__


/**
 * <h2>trace</h2>
 * <p>Function: trace the simple variable among the file.
 * <p>Input: varName, [a list including cycle variables], [a string of the description].
 * <p>Output: Print the variable information to command window, including variable name, variable type, value, function container, the line of the trace code, cycle number, and the description.
 */


//重载
#define TRACE_1(v) Trace(v, #v, __LINE__, __FUNCTION__)
#define TRACE_2(v, opt1) Trace(v, #v, __LINE__, __FUNCTION__, opt1)
#define TRACE_3(v, opt1, opt2) Trace(v, #v, __LINE__, __FUNCTION__, opt1, opt2)
#define TRACE_4(v, opt1, opt2, opt3) Trace(v, #v, __LINE__, __FUNCTION__, opt1, opt2, opt3)
#define TRACE_5(v, opt1, opt2, opt3, opt4) Trace(v, #v, __LINE__, __FUNCTION__, opt1, opt2, opt3, opt4)
#define TRACE_6(v, opt1, opt2, opt3, opt4, opt5) Trace(v, #v, __LINE__, __FUNCTION__, opt1, opt2, opt3, opt4, opt5)
#define TRACE_7(v, opt1, opt2, opt3, opt4, opt5, opt6) Trace(v, #v, __LINE__, __FUNCTION__, opt1, opt2, opt3, opt4, opt5, opt6)
#define TRACE_8(v, opt1, opt2, opt3, opt4, opt5, opt6, opt7) Trace(v, #v, __LINE__, __FUNCTION__, opt1, opt2, opt3, opt4, opt5, opt6, opt7)

//封装
#define TRACE_NARG(...) TRACE_ARG_N(__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define TRACE_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, n, ...) n
#define TRACE_NC(f, ...) f(__VA_ARGS__)
#define TRACE_NB(nargs, ...) TRACE_NC(TRACE_ ## nargs, __VA_ARGS__)
#define TRACE_NA(nargs, ...) TRACE_NB(nargs, __VA_ARGS__)
#define trace(...) TRACE_NA(TRACE_NARG(__VA_ARGS__), __VA_ARGS__)

//函数
template<typename T>
void
Trace(const T var, const string &varName, const int lineNum, const string &function,
      const list<int> &traceNum = list<int>{},
      const string &description = "") {
    //    变量名
    cout << "TRACE [Var=" << varName << "] ";

    //    变量属性：类型
    cout << "[Type=" << typeid(var).name() << "] ";

    //    值
    cout << "[Value=" << var << "] ";

    //    标志：函数名，行号，循环参数
    cout << "[Fun=" << function << ", ";
    cout << "Line=" << lineNum;
    if (!traceNum.empty()) {
        cout << ", Cycle=(";
        for (int it: traceNum) {
            cout << it << " ";
        }
        cout << "\b)";
    }
    cout << "] ";

    //    描述
    if (!description.empty())
        cout << "[Desc: " << description << "] ";

    cout << "\b" << endl;
}


/**
 * <h2>traceArr</h2>
 * <p>Function: trace array variable among the file.
* <p>Input: varName, [a list including cycle variables], [a string of the description].
* <p>Output: Print the variable information to command window, including variable name, variable type, value, function container, the line of the trace code, cycle number, and the description.
*/

//重载
#define TRACEARR_1(v) TraceArr(v, #v, extent<decltype(v)>::value, __LINE__, __FUNCTION__)
#define TRACEARR_2(v, opt1) TraceArr(v, #v, extent<decltype(v)>::value, __LINE__, __FUNCTION__, opt1)
#define TRACEARR_3(v, opt1, opt2) TraceArr(v, #v, extent<decltype(v)>::value, __LINE__, __FUNCTION__, opt1, opt2)
#define TRACEARR_4(v, opt1, opt2, opt3) TraceArr(v, #v, extent<decltype(v)>::value, __LINE__, __FUNCTION__, opt1, opt2, opt3)
#define TRACEARR_5(v, opt1, opt2, opt3, opt4) TraceArr(v, #v, extent<decltype(v)>::value, __LINE__, __FUNCTION__, opt1, opt2, opt3, opt4)
#define TRACEARR_6(v, opt1, opt2, opt3, opt4, opt5) TraceArr(v, #v, extent<decltype(v)>::value, __LINE__, __FUNCTION__, opt1, opt2, opt3, opt4, opt5)
#define TRACEARR_7(v, opt1, opt2, opt3, opt4, opt5, opt6) TraceArr(v, #v, extent<decltype(v)>::value, __LINE__, __FUNCTION__, opt1, opt2, opt3, opt4, opt5, opt6)
#define TRACEARR_8(v, opt1, opt2, opt3, opt4, opt5, opt6, opt7) TraceArr(v, #v, extent<decltype(v)>::value, __LINE__, __FUNCTION__, opt1, opt2, opt3, opt4, opt5, opt6, opt7)

//封装
#define TRACEARR_NARG(...) TRACEARR_ARG_N(__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define TRACEARR_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, n, ...) n
#define TRACEARR_NC(f, ...) f(__VA_ARGS__)
#define TRACEARR_NB(nargs, ...) TRACEARR_NC(TRACEARR_ ## nargs, __VA_ARGS__)
#define TRACEARR_NA(nargs, ...) TRACEARR_NB(nargs, __VA_ARGS__)
#define traceArr(...) TRACEARR_NA(TRACEARR_NARG(__VA_ARGS__), __VA_ARGS__)

//函数
template<typename T>
void
TraceArr(const T var, const string &varName, const int &maxLength, const int lineNum, const string &function,
         const list<int> &traceNum = list<int>{},
         const string &description = "") {
    int i;
    //    参数计算
    int nonEmptyLength = 0;
    while (var[++nonEmptyLength] != '\0');

    //    变量名
    cout << "TRACE [Array=" << varName << "] ";

    //    变量属性：类型，长度
    cout << "[Type=" << typeid(var[0]).name() << ", "
         << "Len=" << nonEmptyLength << "/" << maxLength << "] ";

    //    值
    cout << "[Array={";
    for (i = 0; i < nonEmptyLength; i++)
        cout << var[i] << ", ";
    cout << "\b\b}] ";

    //    标志：函数名，行号，循环参数
    cout << "[Fun=" << function << ", ";
    cout << "Line=" << lineNum;
    if (!traceNum.empty()) {
        cout << ", Cycle=(";
        for (int it: traceNum) {
            cout << it << " ";
        }
        cout << "\b)";
    }
    cout << "] ";

    //    描述
    if (!description.empty())
        cout << "[Desc: " << description << "] ";

    cout << "\b" << endl;
}


//获取时间
string GetTime() {
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    char tmp[64] = {'\0'};
    sprintf(tmp, "%4d-%02d-%02d %02d-%02d-%02d", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond);
    return tmp;
}


//将标准输入流重定向到文件
void InRedirect2File(const string &fileName = "main.in") {
    int stateVar_long = sizeof(fileName);
    char *path = new char[stateVar_long];
    strcpy(path, fileName.c_str());            //需要#include<cstring>，c_str()返回一个临时指针赋给strXk；
    freopen(path, "w", stdout);
}


//将标准输出重定向到文件
void OutRedirect2File(const string &name = "Time") {
    string logName;
    if (name == "Time")
        logName = GetTime() + ".log";
    else
        logName = name + ".log";

    int stateVar_long = sizeof(logName);
    char *path = new char[stateVar_long];
    strcpy(path, logName.c_str());            //需要#include<cstring>，c_str()返回一个临时指针赋给strXk；
    freopen(path, "w", stdout);
}


#endif //CPPTRACE_H
