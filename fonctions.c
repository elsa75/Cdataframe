/** PROJET C : Un Cdataframe
 * Gazin Nathan Elsa Djafar
 * fonction.c est utilisé pour gerer les colonnes hors Cdataframe**/

#include "fonctions.h"

COLUMN * create_column(ENUM_TYPE type, char *title){
    COLUMN * col = (COLUMN *) malloc(sizeof(COLUMN));
    col->title=(char*)malloc((strlen(title)+1)*sizeof (char));
    strcpy(col->title, title);
    col->size = 0;
    col->column_type = type;
    col->max_size = 0;
    col->data = NULL;
    col->index = NULL;
    return col;
}

int insert_value(COLUMN *col, void *value){
    if (col==NULL){return 0;}
    if (col->size + 1 > col->max_size){
        col->data = realloc(col->data, REALOC_SIZE + col->max_size);
        col->max_size += REALOC_SIZE;
    }

    if (col->max_size == 0){
        col->data = (COL_TYPE **)malloc(REALOC_SIZE*sizeof(COL_TYPE*));
        col->max_size=REALOC_SIZE;
    }
    if (value==NULL){
        col->data[col->size] = (COL_TYPE*) malloc (sizeof(COL_TYPE ));
        *(col->data[col->size]) = (COL_TYPE)NULL;
        col->size++;
        return 1;
    }

    switch(col->column_type){
        case UINT:
            col->data[col->size] = (COL_TYPE *) malloc (sizeof(unsigned int));
            *((unsigned int*)col->data[col->size])= *((unsigned int*)value);
            break;

        case INT:
            col->data[col->size] = (COL_TYPE*) malloc (sizeof(signed int));
            *((signed int*)col->data[col->size])= *((signed int *)value);
            break;

        case CHAR:
            col->data[col->size] = (COL_TYPE*) malloc (sizeof(char));
            *((char*)col->data[col->size])= *((char*)value);
            break;

        case FLOAT:
            col->data[col->size] = (COL_TYPE*) malloc (sizeof(float));
            *((float*)col->data[col->size])= *((float*)value);
            break;

        case DOUBLE:
            col->data[col->size] = (COL_TYPE*) malloc (sizeof(double));
            *((double*)col->data[col->size])= *((double*)value);
            break;

        case STRING:
            col->data[col->size] = (COL_TYPE*) malloc (sizeof(char*));
            *((char**)col->data[col->size])= *((char**)value);
            break;

        case STRUCTURE:
            col->data[col->size] = (COL_TYPE*) malloc (sizeof(void*));
            *((void**)col->data[col->size])= *((void**)value);
            break;

        default:
            return 0;
    }
    col->size++;
    return 1;
}

void delete_column(COLUMN ** col){
    printf("**********\n");
    for (int i=0;i<(*col)->size;i++){
        printf("*********1\n");
        free((*col)->data[i]);
    }
    free((*col)->data);
    free((*col)->title);
    free(*col);
    *col = NULL;
}

char * convert_struc(void * structure){
    return (char*) structure;
}

void convert_value(COLUMN* col, unsigned long long int i, char* str, int size){
    switch(col->column_type){
        case UINT:
            snprintf(str, size, "%d", *((unsigned int*)col->data[i]));
            break;

        case INT:
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;

        case CHAR:
            snprintf(str, size, "%c", *((char*)col->data[i]));
            break;

        case FLOAT:
            snprintf(str, size, "%f", *((float*)col->data[i]));
            break;

        case DOUBLE:
            snprintf(str, size, "%lf", *((double *)col->data[i]));
            break;

        case STRING:
            snprintf(str, size, "%s", *((char**)col->data[i]));
            break;

        case STRUCTURE:
            snprintf(str, size, "%s", convert_struc((void*)(col->data[i])));
            break;

        case NULLVAL:
            break;


    }
    if (strlen(str)==0) {
        strcpy(str, "NULL");
    }
}

void print_col(COLUMN* col){
    if (col==NULL || col->size==0 ){
        printf("Colonne vide\n");
        return ;
    }
    char * str;
    for(int i=0;i< col->size;i++){
        int size=10;
        str=(char*)malloc(size*sizeof(col->column_type));
        convert_value(col, i, str, size);
        printf("[%d] %s\n", i, str);
        free(str);
    }
}

COLUMN * create_column_saisie(){
    char str[100];
    int type, size;
    COLUMN *col = NULL;

    printf("Nom de votre colonne : ");
    scanf("%s", str);

    printf("UNIT -> 0      | INT -> 1    | CHAR -> 2\n"
           "FLOAT -> 3     | DOUBLE -> 4 | STRING -> 5\n"
           "STRUCTURE -> 6 |\n"
           "De quelle type sera votre colonne : ");
    scanf(" %d", &type);
    switch (type) {
        case 0:
            col = create_column(UINT, str);
            break;
        case 1:
            col = create_column(INT, str);
            break;
        case 2:
            col = create_column(CHAR, str);
            break;
        case 3:
            col = create_column(FLOAT, str);
            break;
        case 4:
            col = create_column(DOUBLE, str);
            break;
        case 5:
            col = create_column(STRING, str);
            break;
        case 6:
            col = create_column(STRUCTURE, str);
            break;
        default:
            printf("Création impossible\n");
            return NULL;
    }
    printf("Saisir taille de la colonne : ");
    scanf(" %d", &size);
    for (int i = 0; i < size; i++) {
        void *x = NULL;
        switch (col->column_type){
            case UINT:
                x = malloc(sizeof(unsigned int));
                printf("Valeur a ajouter a la colonne de type UNSIGNED INT: ");
                scanf("%u", (unsigned int*)x);
                break;
            case INT:
                x = malloc(sizeof(int));
                printf("Valeur a ajouter a la colonne de type INT: ");
                scanf("%d", (int*)x);
                break;
            case CHAR:
                x = malloc(sizeof(char));
                printf("Valeur a ajouter a la colonne de type CHAR: ");
                scanf(" %c", (char*)x);
                break;
            case FLOAT:
                x = malloc(sizeof(float));
                printf("Valeur a ajouter a la colonne de type FLOAT: ");
                scanf("%f", (float*)x);
                break;
            case DOUBLE:
                x = malloc(sizeof(double));
                printf("Valeur a ajouter a la colonne de type DOUBLE: ");
                scanf("%lf", (double*)x);
                break;
            case STRING:
                x = malloc(100 * sizeof(char));
                printf("Valeur a ajouter a la colonne de type STRING: ");
                scanf("%99s", (char*)x);
                break;
            default:
                break;
        }
        insert_value(col, x);
    }
    return col;
}
