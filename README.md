# Contrôle gestuel

![Language](https://img.shields.io/badge/Language-C++-blue.svg)
![Librairies](https://img.shields.io/badge/Librairies-OpenCV-green.svg)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio%202022-red.svg)

Ce programme simule un contrôle gestuel à l'aide d'une webcam. Il permet de contrôler le curseur de la souris avec un objet de couleur vert.

## Installation

###### Il faut une webcam.

Dans les paramètres du projet :

C/C++ > Général > Autres répertoires include : Ajouter le chemin vers le dossier include de la bibliothèque OpenCV

Éditeur de liens > Général > Répertoires de bibliothèques supplémentaires : Ajouter le chemin vers le dossier lib de la bibliothèque OpenCV

Éditeur de liens > Entrée > Dépendances supplémentaires : Ajouter les librairies suivantes :

opencv_world460d.lib opencv_world460.lib

## Démonstration

![Démonstration](demo.gif)