#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "barbre.h"
#include "general.h"
#include "barbre_bis.h"

int main(int argc, char *argv[])
{
	p_Bnoeud mon_Barbre;
    p_Racine ma_Racine;
	int i, valeur;
    // NN : nombre de valeurs à insérer dans le B-arbre
    int NN;

    if(argc >= 3)
    {
         NN = atoi(argv[2]);
    }

    else
    {
        NN = 30;
    }

    // On tire NN valeurs entre 1 et 100
    int *tab = malloc(NN*sizeof(int)); //= {0,3,4,10,57,59,63,65,67,84,87,13,14,19,27,35,37,47,12,52,27};
    srand(time(NULL));

    for (i =0; i<NN; i++)
    {
        tab[i] = rand()%100;
    }
    // Message d'erreur si les paramètres donnés ne sont pas corrects
	if (argc == 1)
	{
        printf(" On doit indiquer le degré du B-arbre en paramètre. Le second paramètre est le nombre de valeur qu'on insère, par défaut 30. \n");
		exit(2);
	}
    // N : ordre du B-arbre
	N = atoi(argv[1]);
	if (argc >= 3)
    {
        NN =  atoi(argv[2]);
    }
	printf(" L'ordre de B-arbre est de %d.\n", N);

    // Initialisation et remplissage du B-arbre
	mon_Barbre = NULL;
    ma_Racine = NULL;
    printf("\n **** Construction du B-arbre *****\n");
	for (i = 0; i < NN; i++)
	{
        valeur = tab[i];
        if (mon_Barbre == NULL)
		{
			mon_Barbre = creation_Barbre(valeur);
            ma_Racine = creation_Racine(valeur);
		}
		else
		{
            if (recherche_val_Barbre(mon_Barbre, valeur) == VRAI)
				printf(" La valeur s'y trouve déja. \n");
			else
			{
				printf("On insère  la valeur %d.\n ", valeur );
				insertion_Barbre(&mon_Barbre, valeur);
                {
                   // printf("Etat actuel B-arbre : "); affiche_Barbre(mon_Barbre);
                    printf("\n");
                }
			}
		}
	}

  //On range les valeurs du B-arbre dans une liste, on les affiche ensuite
  Liste *chaine = NULL;
  chaine = liste_valeurs(mon_Barbre,chaine);
  chaine = revenir_au_debut(chaine);
  printf("\n **** Affichage des valeurs triées *****\n");
  parcourir_liste(chaine);
  printf("\n");

  // Recherche d'un élément et affichage du suivant/precédent
  int nb_a_chercher = 12;
  printf("\n **** Recherche d'un élement *****\n");
  printf("On cherche l'élement %d. S'il se trouve dans la liste, on affiche le précédent et le suivant : ", nb_a_chercher);
  chercher_element(chaine,nb_a_chercher);
  printf("\n");

  // Recherche dans un intervalle [min,max] (les bornes sont incluses)
  printf("\n **** Recherche d'un intervalle *****\n");
  int min = 5;
  int max = 24;
  printf("On cherche les valeurs comprises entre %d et %d (inclus) : ",min, max);
  chercher_intervalle(chaine, min, max);

  // Suppression d'un élement : On le supprime de la liste puis on construit un nouveau B-Arbre à partir de la liste
  printf("\n **** Supression d'un élement *****\n");
  int nb_a_supprimer = 12;
  Liste *courant = NULL;
  Bnoeud *nouveauArbre;
  int est_dans_arbre = supprimer_element(chaine, nb_a_supprimer);
  if(est_dans_arbre == 1)
  {
      printf("On supprime le nombre %d\n\n", nb_a_supprimer);
      courant = chaine;
      nouveauArbre = creation_Barbre(courant->nombre);
      //ma_Racine = creation_Racine(valeur);
      printf("Le premier B-arbre : "); affiche_Barbre(nouveauArbre);
      courant = courant->suivant;
      while(courant != NULL)
      {
          valeur = courant->nombre;
          if (recherche_val_Barbre(nouveauArbre, valeur) == VRAI)
              printf(" La valeur s'y trouve déja. \n");
          else
          {
              printf("On insère  la valeur %d.\n ", valeur );
              insertion_Barbre(&nouveauArbre, valeur);
              printf("Etat actuel B-arbre : "); affiche_Barbre(nouveauArbre);
              printf("\n");
          }
          courant = courant->suivant;
      }
  Liste *chaine2 = NULL;
  chaine2 = liste_valeurs(nouveauArbre,chaine2);
  chaine2 = revenir_au_debut(chaine2);
  printf("Voici les valeurs triées du nouvel arbre : ");
  parcourir_liste(chaine2);
  printf("On vérifie à partir de la liste initiale des valeurs : ");
  parcourir_liste(chaine);
  printf("\n");
  }
  else
  {
      printf("La valeur à supprimer n'est pas dans l'arbre\n");
  }

return 0;
}
