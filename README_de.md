# CppTrace

<p>
    <img src="https://img.shields.io/github/v/release/ruiyangzhou01/CppTrace?&color=blue&logo=hack-the-box" />
    <img alt="C++" src="https://img.shields.io/badge/-C++-9f62a5?style=flat&logo=cplusplus&logoColor=white" />
</p>

[English](https://github.com/ruiyangzhou01/CppTrace/blob/main/README.md) | [简体中文](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_zh.md) | [Deutsch](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_de.md) | [Español](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_es.md) | [Français](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_fr.md) | [日本語](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_ja.md)

CppTrace ist ein Single-Header-C++14-Trace-Helfer, der Variableninformationen auf die Standardausgabe schreibt. Er besteht aus einer Header-Datei (`CppTrace.h`) und enthält Hilfsfunktionen zum Umleiten der Ausgabe in eine Logdatei.

## Features

- Single-Header-Bibliothek (nur `CppTrace.h`).
- Skalare Variablen mit `trace` verfolgen.
- Feste Arrays mit `traceArr` verfolgen.
- Optionale Schleifenzähler für verschachtelte Schleifen (`std::list<int>`).
- Optionale Beschreibungen pro Trace.
- Ausgabe enthält Variablennamen, `typeid(...).name()`, Wert(e), Funktionsbereich, Zeilennummer, Schleifenindizes und Beschreibung.
- Hilfsfunktionen zum Umleiten von `stdout` in eine Datei (`InRedirect2File`, `OutRedirect2File`).

### Screenshot

![screenshot](README.assets/screenshot.png)

## Anforderungen und Einschränkungen

- C++14-Compiler erforderlich.
- Standardmäßig nur Windows, da `CppTrace.h` `<windows.h>` einbindet und `GetLocalTime` nutzt.
- `traceArr` akzeptiert nur Arrays fester Größe (keine Pointer oder STL-Container). Die verwendete Länge wird durch Scannen nach `\0` ermittelt, daher sollten Arrays mit Nullen initialisiert oder nullterminiert sein.
- Typnamen stammen von `typeid(...).name()` und sind compilerabhängig (nicht demangelt).

## Installation

1. Gehe zur [GitHub-Releases-Seite](https://github.com/ruiyangzhou01/CppTrace/releases).
2. Klappe `Assets` auf und lade die Header-Datei `CppTrace.h` herunter.
3. Binde die Header-Datei in dein Projekt ein.

## Demo bauen

Das Repository enthält `main.cpp` als Beispiel. Unter Windows kannst du mit CMake bauen:

```bash
cmake -S . -B build
cmake --build build
```

## Verwendung

Header einbinden und die Trace-Makros verwenden:

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

Das optionale Argument `cycleVariables` ist eine `std::list<int>` (typischerweise Schleifenindizes). Für eine reine Beschreibung zuerst eine leere Liste (`{}`) übergeben.

### Ausgabeformat

Skalare Traces:

```text
TRACE [Var=int_var] [Type=i] [Value=3] [Fun=main, Line=16, Cycle=(1 2)] [Desc: This is the description]
```

Array-Traces:

```text
TRACE [Array=int_arr] [Type=i, Len=4/60] [Array={2, 5, 4, 9}] [Fun=main, Line=27]
```

## Ausgabe in eine Datei umleiten

Beide Helfer nutzen `freopen`, um `stdout` umzuleiten. Das betrifft alle nachfolgenden Konsolenausgaben:

```cpp
OutRedirect2File("Time");    // Nutzt einen Zeitstempel wie "2026-02-10 13-05-02.log"
OutRedirect2File("trace");   // Schreibt in "trace.log"
InRedirect2File("main.in");  // Leitet stdout nach "main.in" um
```

## Lizenz

[GPL-3.0 License](https://github.com/ruiyangzhou01/CppTrace/blob/main/LICENSE) © ruiyangzhou01
