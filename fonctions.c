#include "fonctions.h"


COLUMN *create_column(char* title){
    COLUMN * x = (COLUMN *) malloc(sizeof(COLUMN));
    strcpy(x->titre, title);
    x->taille_logique = 0;
    x->taille_physique = REALOC_SIZE;
    x->donnees = (int *) malloc(REALOC_SIZE*sizeof(int));
    return x;
}

