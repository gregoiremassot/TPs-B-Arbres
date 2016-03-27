#include <stdio.h>
#include <stdlib.h>
#include "listes.h"
Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    liste->suivant = NULL;
    liste->precedent = NULL;
    return liste;
}

Liste *ajout_element(Liste *chaine, int nb)
{
    Liste *liste = malloc(sizeof(*liste));
    if(chaine != NULL)
    {
        chaine->suivant = liste;
        liste->precedent = chaine;
        liste->nombre = nb;
        liste->suivant = NULL;
        return liste;

    }
    else
    {
        chaine = liste;
        chaine->nombre = nb;
        chaine->suivant = NULL;
        chaine->precedent = NULL;
        return chaine;
    }
}

void parcourir_liste(Liste *chaine)
{
    Liste* p;
    Liste* s;
    Liste *c;
    c = chaine;
    while(c != NULL)
    {
        printf("%d ", c->nombre);
        c = c->suivant;
    }
    printf("\n");
}
void vider_liste(Liste *chaine)
{
    Liste *c = chaine;
    while(c->suivant != NULL)
    {
        c = c->suivant;
        free(c->precedent);
    }
}

Liste *revenir_au_debut(Liste* chaine)
{
    Liste *c = NULL;
    c = chaine;
    while(c->precedent != NULL)
    {
        c = c->precedent;
    }
    return c;
}
void chercher_element(Liste* chaine,int nb)
{
    Liste* p;
    Liste* s;
    Liste *c;
    c = chaine;
    int est_dans_la_liste = 0;
    while(c != NULL)
    {
        if(c->nombre == nb)
        {
            est_dans_la_liste = 1;
            if(c->precedent != NULL)
            {
                p = c->precedent;
                printf("%d ", p->nombre);
            }

            printf("%d ", c->nombre);

            if(c->suivant != NULL)
            {
                s = c->suivant;
                printf("%d ", s->nombre);
            }

        }
       // printf("%d ", c->nombre);
        c = c->suivant;
    }
    if(est_dans_la_liste == 0)
    {
        printf("%d n'est pas dans la liste", nb);
    }
}
void chercher_intervalle(Liste *chaine, int min, int max)
{
    Liste *courant = chaine;
    while(courant != NULL)
    {
        if(courant->nombre >= min && courant->nombre <= max)
        {
            printf("%d ", courant->nombre);
        }
        courant = courant->suivant;
    }
    printf("\n");
}

int supprimer_element(Liste *chaine, int nb)
{
    Liste *courant = chaine;
    Liste *suivant = NULL;
    Liste *precedent = NULL;
    int continuer = 1;
    while(courant != NULL && continuer == 1 )
    {
        if(courant->nombre == nb)
        {
            precedent = courant->precedent;
            suivant= courant->suivant;
            if(precedent != NULL)
            precedent->suivant = suivant;

            if(suivant != NULL)
            suivant->precedent = precedent;

            free(courant);
            continuer = 0;
        }
        if(continuer == 1)
        courant = courant->suivant;
    }
    if(continuer == 1)
       return 0;
    else
       return 1;
}
