#include <stdlib.h>
#include <stdio.h>

# include "barbre.h"
# include "general.h"
#include "barbre_bis.h"
#include "listes.h"

/*Cette fonction affiche dans un ordre croissant les valeurs contenues dans l'arbre */
/*On fait un algorithme récursif */
int est_un_arbre(Bnoeud *arbre)
{
    Bnoeud *noeudCourant = NULL;
    Bnoeud *filsNoeudCourant= NULL;
    noeudCourant = arbre;
    int filsEstUnArbre;
    int estUnArbre = 1;
    int i =0;
    //int FilsestUnArbre = 1;
    if(noeudCourant->fils == NULL)
    {
        noeudCourant->nb_cle = sizeof(noeudCourant->cle)/sizeof(int);
        noeudCourant->nb_cle_propres = sizeof(noeudCourant->cle)/sizeof(int);
        noeudCourant->nb_fils= 0;
        noeudCourant->nb_fils_propres= 0;

    }
    else
    {
        noeudCourant->nb_cle_propres = sizeof(noeudCourant->cle)/sizeof(int);
        noeudCourant->nb_cle = sizeof(noeudCourant->cle)/sizeof(int);
        noeudCourant->nb_fils_propres= sizeof(noeudCourant->fils)/sizeof(Bnoeud);
        noeudCourant->nb_fils= sizeof(noeudCourant->fils)/sizeof(Bnoeud);
        for(i=0; i < sizeof(noeudCourant->fils)/sizeof(Bnoeud);i++)
        {
            filsNoeudCourant = noeudCourant->fils;
            filsEstUnArbre = est_un_arbre(noeudCourant->fils[i]);
            if(filsEstUnArbre != 1)
            {
                estUnArbre = 0;
            }
            noeudCourant->nb_cle += filsNoeudCourant->nb_cle;
            noeudCourant->nb_fils += filsNoeudCourant->nb_fils;
        }
    }
    return estUnArbre;
}

Liste *liste_valeurs(Bnoeud *arbre, Liste *chaine)
{
    Liste *c = chaine;
    Bnoeud *noeudCourant, *noeudFils;
    noeudCourant = arbre;
    noeudCourant->nb_cle = noeudCourant->cpt;
    int i;
    if(noeudCourant->fils != NULL)
    {
        for(i = 0; i < noeudCourant->cpt; i++)
        {
            noeudFils = noeudCourant->fils[i];
            c = liste_valeurs(noeudCourant->fils[i], c);
            //c = ajout_element(c, noeudCourant->cle[i]);
            noeudCourant->nb_cle += noeudFils->nb_cle;
        }
        c = liste_valeurs(noeudCourant->fils[noeudCourant->cpt], c);

    }
    else if(noeudCourant->fils == NULL)
    {
        for(i = 0; i< noeudCourant->cpt; i++)
        {
           c = ajout_element(c, noeudCourant->cle[i]);
        }
    }
    return c;
}

void afficher_valeurs_triees(Bnoeud *arbre)
{
    Bnoeud *noeudCourant;
    noeudCourant = arbre;
    int i;
    if(noeudCourant->fils != NULL)
    {
        for(i = 0; i < noeudCourant->cpt; i++)
        {
            afficher_valeurs_triees(noeudCourant->fils[i]);
            printf("%d ", noeudCourant->cle[i]);
        }
        afficher_valeurs_triees(noeudCourant->fils[noeudCourant->cpt]);

    }
    else if(noeudCourant->fils == NULL)
    {
        for(i = 0; i< noeudCourant->cpt; i++)
        {
            printf("%d ", noeudCourant->cle[i]);
        }
    }
}

void afficher_valeurs_triees_intervalle(Bnoeud *arbre, int inf, int sup)
{
    Bnoeud *noeudCourant;
    noeudCourant = arbre;
    int i;
    if(noeudCourant->fils != NULL)
    {
        for(i = 0; i < noeudCourant->cpt; i++)
        {
            afficher_valeurs_triees_intervalle(noeudCourant->fils[i], inf, sup);
            if(noeudCourant->cle[i] >= inf && noeudCourant->cle[i] <= sup)
            printf("%d ", noeudCourant->cle[i]);
        }
        afficher_valeurs_triees_intervalle(noeudCourant->fils[noeudCourant->cpt], inf, sup);

    }
    else if(noeudCourant->fils == NULL)
    {
        for(i = 0; i< noeudCourant->cpt; i++)
        {
            if(noeudCourant->cle[i] >= inf && noeudCourant->cle[i] <= sup)
            printf("%d ", noeudCourant->cle[i]);
        }
    }
}

Liste* afficher_precedent_suivant(Bnoeud *arbre, int nb, Liste* chaine)
{
    int afficher_nb = 0;
    Liste *liste_initiale;
    if(chaine == NULL)
    {
        liste_initiale = chaine;
       //chaine = initialisation();
       afficher_nb = 1;
    }
    Bnoeud *noeudCourant;
    noeudCourant = arbre;
    int i;
    if(noeudCourant->fils != NULL)
    {
        for(i = 0; i < noeudCourant->cpt; i++)
        {
            afficher_precedent_suivant(noeudCourant->fils[i], nb, chaine);
            chaine = ajout_element(chaine, noeudCourant->fils[i]);
        }
        afficher_precedent_suivant(noeudCourant->fils[noeudCourant->cpt], nb, chaine);

    }
    else if(noeudCourant->fils == NULL)
    {
        for(i = 0; i< noeudCourant->cpt; i++)
        {
            chaine = ajout_element(chaine, noeudCourant->cle[i]);
        }
    }
    if(afficher_nb == 1)
    {
       //parcourir_liste(liste_initiale, nb);
    }
    return chaine;
}
Arbre_split *split_arbre(Bnoeud *arbre, int valeur)
{
    Liste *chaine = NULL;
    Liste *maillon;
    chaine = liste_valeurs(arbre,chaine);
    chaine = revenir_au_debut(chaine);
    maillon = chaine;
    Bnoeud *arbre1 = NULL;
    Bnoeud *arbre2 = NULL;
    int i =0;
    int estDansLaListe = 0;
    int indice = 0;
    while(maillon->suivant != NULL)
    {
        if(maillon->nombre == valeur)
        {
            estDansLaListe = 1;
            indice = i;
        }
        maillon = maillon->suivant;
        i++;
    }
    if(estDansLaListe != 0)
    {
        maillon = chaine;
        arbre1 = creation_Barbre(maillon->nombre);
        for(i = 0; i<indice; i++)
        {
            maillon = maillon->suivant;
            if (recherche_val_Barbre(arbre1, valeur) == FAUX)
            insertion_Barbre(&arbre1, maillon->nombre);
        }
        if(maillon->suivant != NULL)
        {
            maillon = maillon->suivant;
            arbre2 = creation_Barbre(maillon->nombre);
        }
        while(maillon->suivant != NULL)
        {
            maillon = maillon->suivant;
            if (recherche_val_Barbre(arbre2, valeur) == FAUX)
            insertion_Barbre(&arbre2, maillon->nombre);
        }
        Arbre_split *reunion = NULL;
        reunion = malloc(sizeof(Arbre_split));
        reunion->arbre1 = arbre1;
        reunion->arbre2 = arbre2;

    }
    else
    {
        return NULL;
    }
}
