# MagicForest

## Présentation

Au départ, toutes les cases ne sont pas visibles.

Les monstres et trous sont disposés au hasard dans la foret.
Le nombre de monstre s'incrémente à chaque niveau et le nombre de trou s'imcrémente tous les 2 niveaux (au niveau 1, il n'y en a pas)


Au fur et à mesure de la progression de l'agent, les cases se dévoilent.
* Un 'C' représente une crotte
* Un 'V' représente du vent
* Un 'A' représente la position de l'agent
* Un 'M' représent un monstre
* Un 'T' représente un trou
* Un ' ' représente une case vide
* Un '\*' représente une case non explorée

Lorsque l'agent se trouve sur une case portail et sort, une foret de niveau supérieur est générée et on recommence un niveau.


## Système expert

L'implémentation se fait dans les fichiers 
* RuleBase
* KnowledgeBase

Malheureusement, par soucis de niveau technique et de modélisation, nous n'avons pas réussi à l'implémenter mais néanmoins, nous en avons compris le fonctionnement: 
A chaque tour, l'agent met à jour sa base de connaissances pour mettre a jour sa base de fait.
De plus, pour chaque règle nous regardons si sa (ou ses) prémisse appartient à la base de fait et si c'est le cas, alors nous mettons à jour la base de fait avec la conclusion de la règle.
Une fois cette base de faits mise à jour, il ne reste plus qu'à l'agent de choisir ses actions à réaliser. Ses actions sont choisis en fonction du risque du déplacement, plus une case est risquée (présence d'un monstre ou d'une creuvasse) et plus le déplacement est risqué.

Lorsqu'une case est venteuse ou puante, les case voisines voient leur niveau de risque augmenté de 1.
Lorsqu'aucune des cases non explorés et présentes à la frontière du joueur ne présentes aucun risque, alors le joueur choisi celle la moins risquée.

Le but de l'agent est de trouver la case qui brille, qui signale la présence d'un portail. 
