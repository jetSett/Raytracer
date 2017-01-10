# Moteur de lancer de rayon PROJ1 2016 @ ENS LYON
# Par Joël Felderhof, Louis Béthune, Guillaume Coiffier


## Comment faire fonctionner le code :
- taper "cmake ." dans la console, cela créera automatiquement un joli Makefile
- taper "make" pour compiler ce qu'il faut

Pour les gens qui auraient la flemme de taper deux commandes, executez build.sh à la place.

- l'executable s'appelle Raytracer et se trouve dans le dossier bin. Pour qu'il fonctionne, il faut l'appeller avec un argument.
	Cet argument est le nom d'un fichier de configuration (.scn) qui doit être présent dans le dossier scenery.
	tapez par exemple "bin/Raytracer test1"

Pour écrire des fichiers de configuration, se référer au readme du dossier scenery.

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
- [x] Implémenter une classe de lampes et gérer l'éclairage
- [x] Définir un format de fichiers de description de scène et créer un parser en python
			pour les lires
- [ ] Gérer la reflexion des rayons et le caractère transparent des objets.
- [ ] Do a barrel roll


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

Python est ici interfacé avec C++ à travers la librairie Boost.python.
Le fichier parse.cpp contient la fonction qui va appeler le parser python.
Le parser python prend en entrée le nom d'un fichier de config, et renvoie au c++
un tuple d'objets.
La définition de ce tuple est expliquée dans le readme du dossier scn.
