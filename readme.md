# Moteur de lancer de rayon PROJ1 2016

## To-do list

- [ ] Faire un moteur basique comprenant :
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
