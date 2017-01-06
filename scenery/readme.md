# Moteur de lancer de rayon PROJ1 2016
# Langage de description des scènes

## Syntaxe des fichiers .scn

# Conventions
Toute coordonnées sont données sous forme de tuples (x,y,z), à la fois pour les points et les vecteurs.

Les types sont à choisir parmi les suivants :
Plane, Sphere, Triangle, LightPoint

Les matériaux sont à choisir parmi les suivants :
ColorGreen, ColorRed, ColorYellow, ColorCyan, ColorMagenta, ColorBlue

Pour annoter votre fichier scn, utilisez un ;
Tout ce qui se trouve après un ; sur une ligne ne sera pas parsé.

# Préambule
  Le préambule décrit les paramètres globaux de la scène. Les paramètres à remplir sont les suivants :
  - name : un petit nom sympa pour cette scène.
  - width
  - height
  - nb_objects : le nombre total d'objets
  - nb_displayer : le nombre de displayer (= fenêtres donnant sur la même scène mais à des angles différents)
  - layout : l'organisation de ces displayer, de la forme (i,j) => i lignes de j displayer

# Descriptions des objets.

La description des objets commence à partir de la ligne #OBJECTS du fichier.

La définition d'un objet commence par son nom. Il doit être écrit sans espace et directement suivi d'un ":". Ce nom n'apparaitra pas après le parsing, mais cela permet de vous y retrouver dans votre fichier.
les lignes suivantes de la définition dépendent du type de l'objet. Pour chaque type doivent figurer l'intégralité des lignes de configuration sous la forme
entree=parametre. Il est conseillé d'indenter ces lignes pour une meilleure lisibilité.

[] Sphere :
  -type=Sphere
  -material
  -center : les coordonnées du centre de la sphèref
  -radius : le rayon de la sphère

[] Plan :
  -type=Plane
  -material
  -origin : un point par lequel passe le plan
  -normal : un vecteur normal au plan

[] Type Triangle :
  -type=Triangle
  -material
  -p1
  -p2
  -p3 : les trois coordonnées des sommets du triangle

[] Type LampPoint :
  -type=LampPoint
  -pos

[] Type Camera :
   -type=Camera
   -absolut_origin
   -polar_coordinates

## Conventions de codage des données de sortie

Le parser python va renvoyer une liste au code C++. Cette liste contient des tuples représentant chacun toutes les données permettant de créer un objet dans la scène.
Le premier tuple de la liste contient les paramètres globaux de la scène. Contrairement au fichier scn (où l'ordre des paramètres était quelconque), l'ordre des éléments du tuple est obligatoirement le suivant (pour des raisons de décodage en C++) :

tuple0 = (name, nb_objects, width, height, nb_displayer, layout_i,layout_j)

les autres tuples (décrivant des objets) sont de la forme suivante. Attention, chaque objet dispose de paramètres différents. Le type de l'objet est TOUJOURS le premier élément du tuple.

Sphere : (type, material, center, radius)
Plane :  (type, material, origin, normal_x, normal_y, normal_z)
Triangle : (type, material, p1, p2, p3)
Light : (type, pos)
