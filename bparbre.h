#ifndef BPARBRE_INCLUDED
#define BPARBRE_INCLUDED

typedef struct Bpnoeud Bpnoeud;
struct Bpnoeud
{
    int cpt;
    int h;
    int **fils;
    Bpnoeud *voisin;
    int *cle;
    int haut;
};

#endif
