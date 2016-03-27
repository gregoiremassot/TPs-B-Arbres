#ifndef BARBRE_BIS_H_INCLUDED
#define BARBRE_BIS_H_INCLUDED
#include "listes.h"
#include "barbre.h"
typedef struct Arbre_split Arbre_split;
struct Arbre_split
{
    Bnoeud *arbre1;
    Bnoeud *arbre2;
};
//void afficher_valeurs_triees(Bnoeud *arbre);
//void afficher_valeurs_triees_intervalle(Bnoeud *arbre, int inf, int sup);
//Liste* afficher_precedent_suivant(Bnoeud *arbre, int nb, Liste* chaine);
//Liste *liste_valeurs(Bnoeud *arbre, Liste *chaine);
//Arbre_split* split_arbre(Bnoeud *arbre, int valeur);
#endif // BARBRE_BIS_H_INCLUDED
