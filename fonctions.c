#include "fonctions.h"


COLUMN * create_column(char* title){
    COLUMN * x = (COLUMN *) malloc(sizeof(COLUMN));
    strcpy(x->titre, title);
    x->taille_logique = 0;
    x->taille_physique = REALOC_SIZE;
    x->donnees = NULL;
    return x;
}

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

void delete_column(COLUMN *col){
    free(col->donnees);
    col->donnees = NULL;
    free(col);
    col = NULL;
}

void print_col(COLUMN* col){
    for (int i=0; i<col->taille_logique;i++)
        printf("[%d] %d\n", i, *(col->donnees+i));
}

int nb_occurrences(COLUMN *col, int val){
    int nb = 0;
    for (int i=0; i<col->taille_logique;i++){
        if (*(col->donnees+i) == val) {nb++;}
    }
    return nb;
}

int val_precedent(COLUMN *col, int pos){
    if (pos > 0 && pos < col->taille_logique) {return *(col->donnees+pos-1);}
    return 0;
}

int nb_val_sup(COLUMN *col, int val){
    int nb = 0;
    for (int i=0; i<col->taille_logique;i++){
        if (*(col->donnees+i) > val) {nb++;}
    }
    return nb;
}

int nb_val_inf(COLUMN *col, int val){
    int nb = 0;
    for (int i=0; i<col->taille_logique;i++){
        if (*(col->donnees+i) < val) {nb++;}
    }
    return nb;
}

COLUMN ** create_CDataframe(){
    COLUMN ** tab = (COLUMN **) malloc(sizeof(COLUMN *) );
    return tab;
}

void saisie_CDataframe( COLUMN ** cd, int taille_tab){
    cd = realloc(cd, taille_tab * sizeof(COLUMN *));
    char nom[20];
    int nb=0,val;
    for (int i=0; i<taille_tab; i++){
        printf("Saisir nom colonne %d : \n",i+1);
        scanf(" %s", nom);
        *(cd+i) = create_column(nom);
        printf("Saisir nombre de valeur a inserer dans la colonne %s : \n", nom);
        scanf(" %d",&nb);
        for (int j=0;j<nb;j++){
            printf("Saisir valeur %d : \n",j);
            scanf(" %d", &val);
            insert_value(*(cd+i), val);
        }
    }
}

COLUMN ** saisie_dur_CDataframe(COLUMN ** cd){
    int taille_cd = 2;
    char * titre1 = "Nathan";
    char * titre2 = "Manon";
    int  donne1[3] = {1, 2, 3};
    int donne2[3] = {4,5,6};
    cd = realloc(cd, taille_cd * sizeof(COLUMN *));
    *cd = create_column(titre1);
    insert_value(*cd, 1);
    insert_value(*cd, 2);
    insert_value(*cd, 3);
    *(cd+1) = create_column(titre2);
    insert_value((*(cd+1)), 4);
    insert_value((*(cd+1)), 5);
    insert_value((*(cd+1)), 6);
    return cd;
}

void print_CDataframe(COLUMN ** cd, int taille){
    for (int i=0;i<taille;i++){
        printf("%s\n",(*(cd+i))->titre);
        print_col(*(cd+i));
    }
}

void print_colones_x(COLUMN ** cd, int taille, int val){
    if (val <= taille){
        for (int i=0;i<val;i++){
            printf("%s\n",(*(cd+i))->titre);
            print_col(*(cd+i));
        }
    }
}

void print_lignes_x(COLUMN ** cd, int taille, int val){
    for (int i=0;i<taille;i++){
        if ((*(cd+i))->taille_logique <= val){print_col(*(cd+i));}
        else{
            for (int j=0; j<val;j++) {
                printf("[%d] %d\n", j, *((*(cd + j))->donnees + j));
            }
        }
    }
}
