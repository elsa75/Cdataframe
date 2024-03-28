#ifndef CDATAFRAME_FONCTIONS_H
#define CDATAFRAME_FONCTIONS_H

#define REALOC_SIZE 256

typedef struct{
    char titre[20];
    int taille_physique;
    int taille_logique;
    int donnees[REALOC_SIZE];
}COLUMN;

COLUMN *create_column(char* title);

#endif
