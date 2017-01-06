# Moteur de lancer de rayon PROJ1 2016

Comment faire fonctionner le code :
- taper "cmake ." dans la console, cela créera automatiquement un joli Makefile
- taper "make" pour compiler ce qu'il faut

/!\ A priori il faut refaire ceci quand on rajoute des fichiers

## installation de la SFML
Il faut installer le paquet libsfml-dev
il faut aussi installer le paquet libeigen3-dev
Il faut créer le fichier FindSFML.cmake disponible à l'adresse suivante : https://github.com/SFML/SFML/blob/master/cmake/Modules/FindSFML.cmake dans le dossier /usr/share/cmake<votre version>/Modules

## installation de Boost.Python
Il faut installer le paquet boost-all-dev

## To-do list

- [x] Faire un moteur basique comprenant :
	- un modèle de camera simple (double plan)
	- l'intersection rayon/sphère
	- affichage en fonction de la profondeur d'un objet
- [ ] Programme d'affichage en Python : fichier d'input à définir
- [ ]
- [ ]


## Conventions de notation

Intégralité des noms en anglais

Les headers sont en .hpp

Commentez votre code, BORDEL.

- Classe :   NomClasse
- Interface : INomInterface
- Attributs privé : _nomPrive

## Architecture C++

- Class Point
- Class Vect3

/!\ Point et Vect3 sont distinctes !

- Class Ray : contient un point (origine) et un vecteur (direction)
- Interface IShape :

	_methods_:
		- Intersec (Ray)

- Class Sphere :
	- rayon
	- center  
	(for spheres. Triangles for more general shapes later)


## Python

blablabla

## Concepts et idées

- Coordonnées homogènes
