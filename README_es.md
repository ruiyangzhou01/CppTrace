# CppTrace

<p>
    <img src="https://img.shields.io/github/v/release/ruiyangzhou01/CppTrace?&color=blue&logo=hack-the-box" />
    <img alt="C++" src="https://img.shields.io/badge/-C++-9f62a5?style=flat&logo=cplusplus&logoColor=white" />
</p>

[English](https://github.com/ruiyangzhou01/CppTrace/blob/main/README.md) | [简体中文](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_zh.md) | [Deutsch](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_de.md) | [Español](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_es.md) | [Français](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_fr.md) | [日本語](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_ja.md)

CppTrace es un asistente de trazas de C++14 de un solo encabezado que imprime información de variables en la salida estándar. Se entrega como un único archivo (`CppTrace.h`) e incluye funciones auxiliares para redirigir la salida a un archivo de registro.

## Características

- Biblioteca de un solo encabezado (solo `CppTrace.h`).
- Rastrear variables escalares con `trace`.
- Rastrear arreglos de tamaño fijo con `traceArr`.
- Contadores de ciclo opcionales para bucles anidados (`std::list<int>`).
- Descripciones opcionales por traza.
- La salida incluye nombre de variable, `typeid(...).name()`, valor(es), ámbito de la función, número de línea, índices de ciclo y descripción.
- Funciones auxiliares para redirigir `stdout` a un archivo (`InRedirect2File`, `OutRedirect2File`).

### Captura de pantalla

![screenshot](README.assets/screenshot.png)

## Requisitos y limitaciones

- Compilador C++14.
- Solo Windows de forma predeterminada, porque `CppTrace.h` incluye `<windows.h>` y usa `GetLocalTime`.
- `traceArr` acepta solo arreglos de tamaño fijo (no punteros ni contenedores STL). Determina la longitud utilizada buscando `\0`, por lo que los arreglos deben inicializarse en cero o terminar en nulo.
- Los nombres de tipos provienen de `typeid(...).name()` y dependen del compilador (no están desmanglados).

## Instalación

1. Ve a la [página de lanzamientos de GitHub](https://github.com/ruiyangzhou01/CppTrace/releases).
2. Expande `Assets` y descarga el archivo de encabezado `CppTrace.h`.
3. Incluye el encabezado en tu proyecto.

## Compilar la demo

El repositorio incluye `main.cpp` como ejemplo. En Windows puedes compilarlo con CMake:

```bash
cmake -S . -B build
cmake --build build
```

## Uso

Incluye el encabezado y usa los macros de trazado:

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

El argumento opcional `cycleVariables` es una `std::list<int>` (normalmente índices de bucle). Para solo una descripción, pasa primero una lista vacía (`{}`).

### Formato de salida

Trazas escalares:

```text
TRACE [Var=int_var] [Type=i] [Value=3] [Fun=main, Line=16, Cycle=(1 2)] [Desc: This is the description]
```

Trazas de arreglos:

```text
TRACE [Array=int_arr] [Type=i, Len=4/60] [Array={2, 5, 4, 9}] [Fun=main, Line=27]
```

## Redirigir la salida a un archivo

Ambos helpers usan `freopen` para redirigir `stdout`, por lo que afecta a toda la salida posterior:

```cpp
OutRedirect2File("Time");    // Usa una marca de tiempo como "2026-02-10 13-05-02.log"
OutRedirect2File("trace");   // Escribe en "trace.log"
InRedirect2File("main.in");  // Redirige stdout a "main.in"
```

## Licencia

[GPL-3.0 License](https://github.com/ruiyangzhou01/CppTrace/blob/main/LICENSE) © ruiyangzhou01
