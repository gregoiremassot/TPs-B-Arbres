#ifndef LISTES_H_INCLUDED
#define LISTES_H_INCLUDED
typedef struct Liste Liste;
struct Liste
{
    int nombre;
    Liste* suivant;
    Liste* precedent;
};
Liste *ajout_element(Liste *chaine, int nb);
Liste *initialisation();
void parcourir_liste(Liste *chaine);
void vider_liste(Liste *chaine);
Liste *revenir_au_debut(Liste* chaine);
void chercher_element(Liste* chaine, int nb);
int supprimer_element(Liste *chaine, int nb);
void chercher_intervalle(Liste *chaine, int min, int max);
#endif
