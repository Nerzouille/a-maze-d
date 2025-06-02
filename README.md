
# a-maze-d

Réalisation d'un algorithme capable de trouver le moyen le plus rapide de faire parvenir n robots d'un point A à un point B dans un dédale de salles.

Projet entièrement réalisé en C.

## Le projet:

"Votre objectif est de déplacer tous les robots d'un labyrinthe de l'entrée à la sortie, tout en faisant
passer le plus de robots possible en même temps et en un minimum de temps. 
Pour obtenir les informations du labyrinthe, votre programme recevra une description du labyrinthe sur l'écran d'entrée standard"

Il ne peut y avoir qu'un robot par pièce.

__La description contiendra:__
    - Le nombre de robots à l'entrée du labyrinthe
    - Toutes les pièces et leur position
    - Les tunnels reliant chaque pièce

__Compétences:__
    - Lire dans l'entrée standard
    - Parser
    - Graphes
    - Théorie des graphes

## Installation

```bash
Downloads> git clone git@github.com:Nerzouille/amazed.git
...
Downloads/amazed> make
...
```
    
## Usage/Examples

Plusieurs fichiers de test sont disponibles, **laby**, **larbo** et **labyrinth**.

#### Fichier laby:
```bash
3
2 5 0
##start
0 1 2
##end
1 9 2
2 7 8
3 5 4
0-2
0-3
2-1
3-1
2-3
```
- La première ligne montre la présence de 3 robots à faire passer.
- Les lignes composées de 3 éléments sont les pièces, définies comme (Numéro, position x, position y)
- La pièce 0 de coordonnées (1,2) est définie comme le start et la room 1 de coordonnées (9,2) comme la sortie du labyrinthe.
- Les lignes comprenant un '-' sont les tunnels reliant les pièces, composé comme (numéro pièce 1, numéro pièce 2). Les tunnels vont dans les deux sens.

#### Démonstration avec laby :
```bash
amazed> ./amazed < laby 
    #number_of_robots
    3
    #rooms
    2 5 0
    ##start
    0 1 2
    ##end
    1 9 2
    2 7 8
    3 5 4
    #tunnels
    0-2
    0-3
    2-1
    3-1
    2-3
    #moves
    P1-2 P2-3
    P1-1 P2-1 P3-2
    P3-1
```

Le programme affiche les informations du labyrinthe après parsing, puis les mouvements de chaque robot à chaque tour (une ligne = un tour), représentés (P numéro du robot, -, numéro de la salle ou le robot se trouve).

Le fichier de test et démonstration le plus complet est **__larbo__**.

## Authors

- LECERF Manech

- SMOTER Noa ([LinkedIn](https://www.linkedin.com/in/noa-smoter/) / [Portfolio](https://noasmoter.vercel.app/))
