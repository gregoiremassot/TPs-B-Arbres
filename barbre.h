#ifndef BARBRE_INCLUDED
#define BARBRE_INCLUDED

/*
   Mihaela Juganaru-Mathieu : le 15 septembre 2015
*/

/* definitions de types pour le B-arbre et la collection des fonctions */
/* degré du B-arbre */

int N; // Egal au "m" du cours

typedef struct Bnoeud
{
          int cpt; // nb clés : entre 0 et 2N
		  int *cle; // Liste des clés
		  int haut; // haut : la hauteur du noeud, 0 pour la racine
          int est_une_racine;
          int nb_cle;
          int nb_cle_propres;
          int nb_fils;
          int nb_fils_propres;
		  int des;
		  int color;
		  struct Bnoeud **fils;
		  struct Bnoeud *pere;
          struct Bnoeud *frere_gauche;
          struct Bnoeud *frere_droite;

} Bnoeud,* p_Bnoeud; //le type Bnoeud est le type noeud même et p_BNoeud est le type pointeur de B
typedef struct Racine
{
          int cpt; // nb valeurs gardées : entre 0 et 2N
          int *cle; // Liste des clés
          int des;
          int color;
          struct Feuille **fils;


} Racine,* p_Racine; //le type Bnoeud est le type noeud même et p_BNoeud est le type pointeur de B

typedef struct Feuille
{
          int cpt; // nb valeurs gardées : entre 0 et 2N
          int *cle; // Liste des clés
          struct Racine *pere;
          struct Feuille *frere_gauche;
          struct Feuille *frere_droite;

} Feuille,* p_Feuille; //le type Bnoeud est le type noeud même et p_BNoeud est le type pointeur de B

p_Bnoeud creation_Barbre(int valeur);

int recherche_val_Barbre(p_Bnoeud x, int valeur);

void insertion_Barbre(p_Bnoeud *x, int val);

void affiche_valeurs(p_Bnoeud x);

void split_noeud(p_Bnoeud x, int *m, p_Bnoeud *aux);

void affiche_Barbre(p_Bnoeud x);

void affiche_noeud(p_Bnoeud x);
#endif // BARBRE_INCLUDED
