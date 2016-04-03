--- Arguments ---

Le premier argument est l'ordre du B+-arbre
Le second argument est le nombre de valeurs à insérer !! Il faut aussi modifier cet argument

-- Choix des nombres ---

Les nombres sont choisis au hasard entre 0 et 99 par une fonction aléatoire (modifiable)

-- Les fonctions implémentées ou non ---

Implémentées : Insertion/Affichage/Recherche/Successeur/Predecesseur/Recherche dans l'intervalle/Supression
Non Implémentées : Affichage++ / Vérification structure / Split+ join

-- #define AFFICHER_DETAILS --

Ce define du barbre.c affiche ou non les printfs de barbres.c s'il est mis à 1 ou 0 respectivement. Par défaut il est à 0 pour plus de lisibilité

-- Compilation & Execution --

gcc -o Arbres barbre.c barbre.h listes.c listes.h general.h main.c barbre_bis.c barbre_bis.h
./Arbres 2 50


 