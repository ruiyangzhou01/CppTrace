# CppTrace

<p>
    <img src="https://img.shields.io/github/v/release/ruiyangzhou01/CppTrace?&color=blue&logo=hack-the-box" />
    <img alt="C++" src="https://img.shields.io/badge/-C++-9f62a5?style=flat&logo=cplusplus&logoColor=white" />
</p>

[English](https://github.com/ruiyangzhou01/CppTrace/blob/main/README.md) | [简体中文](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_zh.md) | [Deutsch](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_de.md) | [Español](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_es.md) | [Français](https://github.com/ruiyangzhou01/CppTrace/blob/main/README_fr.md)

CppTrace est une bibliothèque de journalisation légère pour tracer les variables C++.

## Fonctionnalités

- Tracer des variables scalaires dans un fichier.
- Tracer des variables de tableau dans un fichier.
- Tracer des variables dans des boucles (avec des compteurs de cycle).
- Ajouter des descriptions aux traces.
- La sortie inclut le nom, le type et la valeur de la variable, la portée de la fonction, la ligne du trace, l'indice de cycle et la description.

### Capture d’écran

![screenshot](README.assets/screenshot.png)

## Installation

1. Rendez-vous sur la [page des versions GitHub](https://github.com/ruiyangzhou01/CppTrace/releases).
2. Dépliez `Assets` et téléchargez le fichier d’en-tête `CppTrace.h`.
3. Incluez le fichier d’en-tête dans votre projet.

## Utilisation

La bibliothèque fournit deux API principales :

```cpp
trace(varName, [cycleVariables], [description]);
traceArr(varName, [cycleVariables], [description]);
```

Incluez d’abord le fichier d’en-tête avec `#include "CppTrace.h"`, puis appelez les deux fonctions dans votre programme. Elles affichent les informations sur les variables dans la console, notamment le nom, le type, la valeur, la portée de la fonction, la ligne du trace, l’indice de cycle et la description.

## Todo

- Prise en charge de l’écriture dans un fichier
- Fournir une API pour faciliter le développement secondaire

## Licence

[GPL-3.0 License](https://github.com/ruiyangzhou01/CppTrace/blob/main/LICENSE) © ruiyangzhou01
