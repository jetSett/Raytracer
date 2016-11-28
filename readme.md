# Moteur de lancer de rayon PROJ1 2016

## To-do list

- [ ]
- [ ]
- [ ]
- [ ]


## Conventions de notation

Intégralité des noms en anglais

# C++ :

- Classe :   NomClasse
- Interface : INomInterface
- Attributs privé : _nomprive

## Architecture

- Class Point
- Class Vecteur

/!\ CPoint et CVecteur sont distinctes !

- Class CRay : contient un point (origine) et un vecteur (direction)
- Interface IShape :

	_methods_:
		- Intersec (Ray, Object)

	Class Shape :
		- rayon
		- center  
		(for spheres. Triangles for more general shapes later)
