# CppTrace

<p>
    <img src="https://img.shields.io/github/v/release/ruiyangzhou01/CppTrace?&color=blue&logo=hack-the-box" />
    <img alt="C++" src="https://img.shields.io/badge/-C++-9f62a5?style=flat&logo=cplusplus&logoColor=white" />
</p>

[English](https://github.com/ruiyangzhou01/CppTrace/blob/main/README.md) | [简体中文](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_zh.md) | [Deutsch](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_de.md) | [Español](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_es.md) | [Français](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_fr.md)

CppTrace ist eine schlanke Logging-Bibliothek zum Nachverfolgen von C++-Variablen.

## Features

- Skalare Variablen in einer Datei verfolgen.
- Array-Variablen in einer Datei verfolgen.
- Variablen in Schleifen verfolgen (mit Schleifenzähler).
- Beschreibungen zu Traces hinzufügen.
- Die Ausgabe enthält Variablenname, Typ, Wert, Funktionsbereich, Trace-Zeilennummer, Schleifenindex und Beschreibung.

### Screenshot

![screenshot](README.assets/screenshot.png)

## Installation

1. Gehe zur [GitHub-Releases-Seite](https://github.com/ruiyangzhou01/CppTrace/releases).
2. Klappe `Assets` auf und lade die Header-Datei `CppTrace.h` herunter.
3. Binde die Header-Datei in dein Projekt ein.

## Verwendung

Die Bibliothek stellt zwei Haupt-APIs bereit:

```cpp
trace(varName, [cycleVariables], [description]);
traceArr(varName, [cycleVariables], [description]);
```

Binde zuerst die Header-Datei mit `#include "CppTrace.h"` ein und rufe dann die beiden Funktionen in deinem Programm auf. Sie geben die Variableninformationen in der Konsole aus, einschließlich Variablenname, Typ, Wert, Funktionsbereich, Trace-Zeilennummer, Schleifenindex und Beschreibung.

## Todo

- Unterstützung für die Ausgabe in eine Datei
- API bereitstellen, um die Weiterentwicklung zu erleichtern

## Lizenz

[GPL-3.0 License](https://github.com/ruiyangzhou01/CppTrace/blob/main/LICENSE) © ruiyangzhou01
