--- Arguments ---

Le premier argument est l'ordre du B+-arbre
Le second argument est le nombre de valeurs � ins�rer !! Il faut aussi modifier cet argument

-- Choix des nombres ---

Les nombres sont choisis au hasard entre 0 et 99 par une fonction al�atoire (modifiable)

-- Les fonctions impl�ment�es ou non ---

Impl�ment�es : Insertion/Affichage/Recherche/Successeur/Predecesseur/Recherche dans l'intervalle/Supression
Non Impl�ment�es : Affichage++ / V�rification structure / Split+ join

-- #define AFFICHER_DETAILS --

Ce define du barbre.c affiche ou non les printfs de barbres.c s'il est mis � 1 ou 0 respectivement. Par d�faut il est � 0 pour plus de lisibilit�

-- Compilation & Execution --

gcc -o Arbres barbre.c barbre.h listes.c listes.h general.h main.c barbre_bis.c barbre_bis.h
./Arbres 2 50


 