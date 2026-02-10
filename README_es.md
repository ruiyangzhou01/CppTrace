# CppTrace

<p>
    <img src="https://img.shields.io/github/v/release/ruiyangzhou01/CppTrace?&color=blue&logo=hack-the-box" />
    <img alt="C++" src="https://img.shields.io/badge/-C++-9f62a5?style=flat&logo=cplusplus&logoColor=white" />
</p>

[English](https://github.com/ruiyangzhou01/CppTrace/blob/main/README.md) | [简体中文](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_zh.md) | [Deutsch](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_de.md) | [Español](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_es.md) | [Français](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_fr.md)

CppTrace es una biblioteca de registro ligera para rastrear variables de C++.

## Características

- Rastrear variables escalares en un archivo.
- Rastrear variables de arreglo en un archivo.
- Rastrear variables dentro de bucles (con contadores de ciclo).
- Añadir descripciones a los rastreos.
- La salida incluye el nombre, tipo y valor de la variable, el ámbito de la función, la línea del rastreo, el índice de ciclo y la descripción.

### Captura de pantalla

![screenshot](README.assets/screenshot.png)

## Instalación

1. Ve a la [página de lanzamientos de GitHub](https://github.com/ruiyangzhou01/CppTrace/releases).
2. Expande `Assets` y descarga el archivo de cabecera `CppTrace.h`.
3. Incluye el archivo de cabecera en tu proyecto.

## Uso

La biblioteca ofrece dos API principales:

```cpp
trace(varName, [cycleVariables], [description]);
traceArr(varName, [cycleVariables], [description]);
```

Primero incluye el archivo de cabecera con `#include "CppTrace.h"` y luego llama a las dos funciones en tu programa. Imprimen la información de la variable en la consola, incluyendo el nombre, tipo, valor, ámbito de la función, línea del rastreo, índice de ciclo y descripción.

## Todo

- Soporte para imprimir en un archivo
- Proporcionar una API para facilitar el desarrollo secundario

## Licencia

[GPL-3.0 License](https://github.com/ruiyangzhou01/CppTrace/blob/main/LICENSE) © ruiyangzhou01
