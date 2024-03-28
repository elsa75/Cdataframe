#include "fonctions.h"


COLUMN *create_column(char* title){
    COLUMN * x = (COLUMN *) malloc(sizeof(COLUMN));
    strcpy(x->titre, title);
    x->taille_logique = 0;
    x->taille_physique = REALOC_SIZE;
    x->donnees = NULL;
    return x;
}
//  (int *) malloc(REALOC_SIZE*sizeof(int))

int insert_value( COLUMN * mycol, int val ){
    if (mycol->donnees == NULL) {
        mycol->donnees = (int *) malloc(REALOC_SIZE * sizeof(int));
        *(mycol->donnees + mycol->taille_logique) = val;
        mycol->taille_logique+=1;
        return 1;
    }
    if (mycol->taille_physique <= mycol->taille_logique){
        mycol->donnees = realloc(mycol->donnees, sizeof(int)*REALOC_SIZE + mycol->taille_physique);
        mycol->taille_physique += REALOC_SIZE;
        *(mycol->donnees + mycol->taille_logique) = val;
        mycol->taille_logique+=1;
        return 1;
    }
    if (mycol->taille_physique > mycol->taille_logique) {
        *(mycol->donnees + mycol->taille_logique) = val;
        mycol->taille_logique += 1;
        return 1;
    }
    return 0;
}

void delete_column(COLUMN *col){    // Je sais pas trop comment faire
    free(col->donnees);
    col->donnees = NULL;
    col = NULL;
}

void print_col(COLUMN* col){
    for (int i=0; i<col->taille_logique;i++)
        printf("[%d] %d\n", i, *(col->donnees+i));
}