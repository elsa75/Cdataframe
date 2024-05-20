#ifndef PROJET_CDATAFRAMEV2_FONCTIONS_H
#define PROJET_CDATAFRAMEV2_FONCTIONS_H
#define REALOC_SIZE 256
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};

typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};

typedef union column_type COL_TYPE ;

struct column {
    char * title;
    unsigned int size; //logical size
    unsigned int max_size; //physical size
    ENUM_TYPE column_type;
    COL_TYPE ** data; // array of pointers to stored data
    unsigned long long int * index; // array of integers
};

typedef struct column COLUMN;

/**
 * Crée un colonne vide,
 * Prend en paramètre :
 * Un ENUM_TYPE le type de la colonne
 * Un string pour le nom de la colonne
 * Renvoie un pointeur sur la colonne
 * **/
COLUMN * create_column(ENUM_TYPE type, char *title);

/**
 * Ajoute une valeur à la colonne,
 * Prend en paramètre :
 * Un  pointeur sur une colonne
 * Un pointeur sur la valeur à ajouter
 * Renvoie 1 si l'ajout réussi sinon 0
 * **/
int insert_value(COLUMN *col, void *value);

/**
 * Supprime une colonne,
 * Prend en paramètre :
 * Un double pointeur sur une colonne
 * Ne renvoi rien car supprimé
 * **/
void delete_column(COLUMN **col);

/**
 * Convetie n'importe quelle type en chaine de caratère,
 * Prend en paramètre :
 * Un  pointeur sur une colonne
 * Un indice sur l'élément à converir
 * Un string qui sera l'élément convertie
 * Un int pour la taille max du string après conversion
 * Ne renvoie rien car ajouté
 * **/
void convert_value(COLUMN *col, unsigned long long int i, char * str, int size);

/**
 * Convetie n'importe quelle type de structure en chaine de caratère,
 * Prend en paramètre :
 * Un pointeur sur une structure
 * Renvoie un string
 * **/
char * convert_struc(void * structure);

/**
 * Affiche une colonne,
 * Prend en paramètre :
 * Un pointeur sur une colonne
 * Ne renvoie rine car affiché
 * **/
void print_col(COLUMN* col);

/**
 * Permet de saisir une colonne selon d'utilisateur,
 * * Prend en paramètre :
 * Renvoie un poit=nteur sur la colonne
 * **/
COLUMN * create_column_saisie();

#endif
