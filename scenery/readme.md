# Moteur de lancer de rayon PROJ1 2016
# Langage de description des scènes

Comment executer un fichier .scn :
- TODO

## Syntaxe des fichiers .scn

# Conventions
Toute coordonnées sont données sous forme de tuples (x,y,z), à la fois pour les points et les vecteurs.

# Préambule
  Le préambule décrit les paramètres globaux de la scène. Les paramètres à remplir sont les suivants :
  - name : un petit nom sympa pour cette scène.
  - width
  - height

# Descriptions des objets.

La description des objets commence à partir de la ligne #OBJECTS du fichier.

La définition d'un objet commence par son nom et son type. Il doit être écrit sans espace et directement suivi d'un ":". De l'autre côté du ":" doit être précisé le type de l'objet. Ce type doit figurer dans les suivants :
    - Plane
    - Sphere
    - Triangle
les lignes suivantes de la définition dépendent du type de l'objet. Pour chaque type doivent figurer l'intégralité des lignes de configuration sous la forme
entree=parametre. Il est conseillé d'indenter ces lignes pour une meilleure lisibilité.

[] Type plane :
  -origin : un point par lequel passe le plan
  -normal : un vecteur normal au plan

[] Type Triangle :
  - p1
  - p2
  - p3
  c'est à dire les trois coordonnées des sommets du triangle

[] Type Sphere :
  -center : les coordonnées du centre de la sphèref
  -radius : le rayon de la sphère


# Descriptions des lampes.
La description des lampes commence à partir de la ligne #LIGHTS du fichier.
Elle est sensiblement la même que celle des objets, excepté pour le type (il n'y en a qu'un seul, donc on ne le précise pas). Les configurations nécessaires pour les lampes sont :
- TODO
-
