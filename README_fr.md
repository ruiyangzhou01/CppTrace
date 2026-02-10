# CppTrace

<p>
    <img src="https://img.shields.io/github/v/release/ruiyangzhou01/CppTrace?&color=blue&logo=hack-the-box" />
    <img alt="C++" src="https://img.shields.io/badge/-C++-9f62a5?style=flat&logo=cplusplus&logoColor=white" />
</p>

[English](https://github.com/ruiyangzhou01/CppTrace/blob/main/README.md) | [简体中文](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_zh.md) | [Deutsch](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_de.md) | [Español](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_es.md) | [Français](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_fr.md) | [日本語](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_ja.md)

CppTrace est un assistant de traçage C++14 à en-tête unique qui imprime les informations des variables sur la sortie standard. Il est fourni sous la forme d’un seul fichier (`CppTrace.h`) et inclut des fonctions d’aide pour rediriger la sortie vers un fichier log.

## Fonctionnalités

- Bibliothèque à en-tête unique (uniquement `CppTrace.h`).
- Tracer des variables scalaires avec `trace`.
- Tracer des tableaux de taille fixe avec `traceArr`.
- Compteurs de cycle optionnels pour les boucles imbriquées (`std::list<int>`).
- Descriptions optionnelles pour chaque trace.
- La sortie inclut le nom de la variable, `typeid(...).name()`, les valeurs, la portée de la fonction, le numéro de ligne, les indices de cycle et la description.
- Fonctions d’aide pour rediriger `stdout` vers un fichier (`InRedirect2File`, `OutRedirect2File`).

### Capture d’écran

![screenshot](README.assets/screenshot.png)

## Prérequis et limitations

- Compilateur C++14.
- Windows uniquement par défaut, car `CppTrace.h` inclut `<windows.h>` et utilise `GetLocalTime`.
- `traceArr` accepte uniquement les tableaux de taille fixe (pas les pointeurs ni les conteneurs STL). La longueur utilisée est déterminée en recherchant `\0`, donc les tableaux doivent être initialisés à zéro ou terminés par un caractère nul.
- Les noms de type proviennent de `typeid(...).name()` et dépendent du compilateur (non démanglés).

## Installation

1. Rendez-vous sur la [page des versions GitHub](https://github.com/ruiyangzhou01/CppTrace/releases).
2. Dépliez `Assets` et téléchargez le fichier d’en-tête `CppTrace.h`.
3. Incluez l’en-tête dans votre projet.

## Compiler la démo

Le dépôt inclut `main.cpp` en exemple. Sous Windows, vous pouvez le compiler avec CMake :

```bash
cmake -S . -B build
cmake --build build
```

## Utilisation

Incluez l’en-tête et utilisez les macros de traçage :

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

L’argument optionnel `cycleVariables` est une `std::list<int>` (généralement des indices de boucle). Pour une simple description, passez d’abord une liste vide (`{}`).

### Format de sortie

Traces scalaires :

```text
TRACE [Var=int_var] [Type=i] [Value=3] [Fun=main, Line=16, Cycle=(1 2)] [Desc: This is the description]
```

Traces de tableaux :

```text
TRACE [Array=int_arr] [Type=i, Len=4/60] [Array={2, 5, 4, 9}] [Fun=main, Line=27]
```

## Rediriger la sortie vers un fichier

Les deux helpers utilisent `freopen` pour rediriger `stdout`, ce qui affecte toutes les sorties suivantes :

```cpp
OutRedirect2File("Time");    // Utilise un horodatage comme "2026-02-10 13-05-02.log"
OutRedirect2File("trace");   // Écrit dans "trace.log"
InRedirect2File("main.in");  // Redirige stdout vers "main.in"
```

## Licence

[GPL-3.0 License](https://github.com/ruiyangzhou01/CppTrace/blob/main/LICENSE) © ruiyangzhou01
