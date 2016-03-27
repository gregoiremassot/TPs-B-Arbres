#include "bparbre.h"

void insertion_Bparbre(Bpnoeud *Bpracine, int val)
{
    Bpnoeud *noeudCourant;
    noeudCourant = Bpracine;
    int i;
    while(noeudCourant->haut != 0)
    {
        i=0;
//        while(val < noeudCourant->fils[i]->cle[i])
//        {
//           i++;
//        }
        noeudCourant = noeudCourant->fils[i];
    }
    i=0;
    while(val < noeudCourant->cle[i])
    {
       i++;
    }

}
