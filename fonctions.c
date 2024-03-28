#include "fonctions.h"


COLUMN *create_column(char* title){
    COLUMN * x = (COLUMN *) malloc(sizeof(COLUMN));
    strcpy(x->titre, title);
    x->taille_logique = 0;
    x->taille_physique = REALOC_SIZE;
    x->donnees = (int *) malloc(REALOC_SIZE*sizeof(int));
    return x;
}

int insert_value( COLUMN * mycol, int val ) {
    if (mycol->taille_physique <= mycol->taille_logique) {
        mycol->donnees = realloc(mycol->donnees, sizeof(int)*REALOC_SIZE + mycol->taille_physique);
        mycol->taille_physique += REALOC_SIZE;
    }
    *(mycol->donnees + mycol->taille_logique) = val;
    mycol->taille_logique+=1;
    return 1;
}
