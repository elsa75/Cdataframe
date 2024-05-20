#include "cdataframe.h"


CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size){
    int taille = 10;
    char * col_name = (char*)malloc(sizeof(char)*taille);

    CDATAFRAME * cdf = lst_create_list();

    lnode *ptmp = (lnode *) malloc(sizeof(lnode));
    cdf->head = ptmp;
    printf("Saisir le nom de la colonne %d : ",1);
    scanf("%s",col_name);
    ptmp->data = create_column(cdftype[0],col_name);
    ptmp->next = NULL;
    ptmp->prev = NULL;
    lnode * tmp = cdf->head;
    lnode * tm = cdf->head;

    for (int i=1;i<size;i++){
        tmp->next = (lnode *) malloc(sizeof(lnode));
        printf("Saisir le nom de la colonne %d : ",i+1);
        scanf("%s",col_name);
        tmp->next->data = create_column(cdftype[i],col_name);
        if(tmp==cdf->head){
            tmp = tmp->next;
            tmp->prev= tm;
        }
        else{
            tmp= tmp->next;
            tm = tm->next;
            tmp->prev = tm;
        }
    }
    cdf->tail= tmp;
    cdf->tail->next = NULL;
    free(col_name);
    return cdf;
}

void delete_cdataframe(CDATAFRAME **cdf){
    lst_delete_list((list*)*cdf);
    *cdf=NULL;
}

void delete_column_cdf(CDATAFRAME *cdf, char *col_name){
    lnode *tmp = cdf->head;
    COLUMN *col;
    while(tmp != NULL){
        col = tmp->data;
        if (strcmp(col_name, col->title) == 0){
            lst_delete_lnode(cdf, tmp);
            free(col->data);
            free(col);
            printf("COLONNE SUPPRIME\n");
        }
        tmp = tmp->next;
    }
}

int get_cdataframe_cols_size(CDATAFRAME *cdf){
    lnode * tmp = cdf->head;
    int nb=0;
    while (tmp!=NULL) {
        tmp = tmp->next;
        nb++;
    }
    return nb;
}

void print_cdataframe(CDATAFRAME * cdf){
    if (cdf==NULL || cdf->head==NULL){
        printf("Cdataframe vide\n");
        return ;
    }
    lnode * tmp;
    tmp = cdf->head;
    int i=0;
    while (tmp!=NULL) {
        COLUMN *col = tmp->data;
        printf("| %s |\t", col->title);
        tmp = tmp->next;
    }
    printf("\n");
    tmp = cdf->head;
    while(i< ((COLUMN*)(tmp->data))->size){
        while (tmp!=NULL) {
            COLUMN* col = tmp->data;
            char * str = NULL;
            int size=10;
            str=(char*)malloc(size*sizeof(col->column_type));
            convert_value(col, i, str, size);
            printf("[%d] %s \t", i, str);
            free(str);
            tmp = tmp->next;
        }
        printf("\n");
        tmp = cdf->head;
        i++;
    }
}

void printf_col_partir_x(CDATAFRAME * cdf, int x){
    int lig=0;
    if (cdf==NULL || cdf->head==NULL){
        printf("Cdataframe vide\n");
        return ;
    }
    lnode * tmp;
    tmp = cdf->head;
    while (tmp!=NULL && lig < x){
        lig++;
        tmp = tmp->next;
    }
    while (tmp!=NULL && lig >= x){
        print_col(tmp->data);
        lig++;
        tmp = tmp->next;
    }
}

void printf_ligne_partir_x(CDATAFRAME * cdf, int x) {
    if (cdf == NULL || cdf->head == NULL) {
        printf("Cdataframe vide\n");
        return;
    }
    lnode *tmp;
    tmp = cdf->head;
    COLUMN *col;
    while (tmp != NULL) {
        char *str;
        col = (COLUMN *) tmp->data;
        for (int i = x; i < col->size; i++) {
            int size = 10;
            str = (char *) malloc(size * sizeof(col->column_type));
            convert_value(col, i, str, size);
            printf("[%d] %s\n", i, str);
            free(str);
        }
        tmp = tmp->next;
    }
}

void ajouter_ligne_cdf(CDATAFRAME * cdf){
    if (cdf==NULL || cdf->head==NULL){
        printf("Cdataframe vide\n");
        return ;
    }
    lnode * tmp;
    tmp = cdf->head;
    while (tmp!=NULL){
        void * x;
        COLUMN *col = (COLUMN*)tmp->data;
        switch (((COLUMN*)(tmp->data))->column_type){
            case UINT:
                x = malloc(sizeof(unsigned int));
                if (x == NULL) {
                    printf("Erreur d'allocation de mémoire\n");
                    return;
                }
                printf("Valeur à ajouter à la colonne \"%s\" de type UNSIGNED INT: ", col->title);
                scanf("%u", (unsigned int*)x);
                break;

            case INT:
                x = malloc(sizeof(int));
                if (x == NULL) {
                    printf("Erreur d'allocation de mémoire\n");
                    return;
                }
                printf("Valeur à ajouter à la colonne \"%s\" de type INT: ", col->title);
                scanf("%d", (int*)x);
                break;

            case CHAR:
                x = malloc(sizeof(char));
                if (x == NULL) {
                    printf("Erreur d'allocation de mémoire\n");
                    return;
                }
                printf("Valeur à ajouter à la colonne \"%s\" de type CHAR: ", col->title);
                scanf(" %c", (char*)x);
                break;

            case FLOAT:
                x = malloc(sizeof(float));
                if (x == NULL) {
                    printf("Erreur d'allocation de mémoire\n");
                    return;
                }
                printf("Valeur à ajouter à la colonne \"%s\" de type FLOAT: ", col->title);
                scanf("%f", (float*)x);
                break;

            case DOUBLE:
                x = malloc(sizeof(double));
                if (x == NULL) {
                    printf("Erreur d'allocation de mémoire\n");
                    return;
                }
                printf("Valeur à ajouter à la colonne \"%s\" de type DOUBLE: ", col->title);
                scanf("%lf", (double*)x);
                break;

            case STRING:
                x = malloc(100 * sizeof(char)); // Assumes maximum string length is 100
                if (x == NULL) {
                    printf("Erreur d'allocation de mémoire\n");
                    return;
                }
                printf("Valeur à ajouter à la colonne \"%s\" de type STRING: ", col->title);
                scanf("%99s", (char*)x);
                break;

            default:
                printf("Type de colonne non pris en charge\n");
                return;
        }
        insert_value(tmp->data, x);
        tmp = tmp->next;
    }
}

CDATAFRAME * create_cdataframe_dur(){
    char * tab[3] = {"a","b", "c"};
    ENUM_TYPE cdftype [3] = {3,4,6};
    int taille = 10;

    CDATAFRAME * cdf = lst_create_list();

    lnode *ptmp = (lnode *) malloc(sizeof(lnode));
    cdf->head = ptmp;
    ptmp->data = create_column(cdftype[0],"a");
    ptmp->next = NULL;
    ptmp->prev = NULL;
    lnode * tmp = cdf->head;
    lnode * tm = cdf->head;

    for (int i=1;i<3;i++){
        tmp->next = (lnode *) malloc(sizeof(lnode));
        tmp->next->data = create_column(cdftype[i],tab[i]);
        if(tmp==cdf->head){
            tmp = tmp->next;
            tmp->prev= tm;
        }
        else{
            tmp= tmp->next;
            tm = tm->next;
            tmp->prev = tm;
        }
    }
    cdf->tail= tmp;
    cdf->tail->next = NULL;
    int a=1,b=2,c=3;
    char x='a',y='b',z='c';
    double s=4.5,t=5.5,u=6.5;
    insert_value((COLUMN *)(cdf->head->data), &a);
    insert_value(cdf->head->data, &b);
    insert_value(cdf->head->data, &c);
    insert_value(cdf->head->next->data, &x);
    insert_value(cdf->head->next->data, &y);
    insert_value(cdf->head->next->data, &z);
    insert_value(cdf->head->next->next->data, &t);
    insert_value(cdf->head->next->next->data, &u);
    insert_value(cdf->head->next->next->data, &s);
    return cdf;
}

CDATAFRAME * create_cdataframe_saisi(){
    int size;
    printf("Saisir le nombre de colonne de votre CDATAFRAME : ");
    scanf(" %d", &size);
    ENUM_TYPE tab[size];
    for (int j = 0; j < size; j++) {
        printf("UNIT -> 2      | INT -> 3    | CHAR -> 4\n"
               "FLOAT -> 5     | DOUBLE -> 6 | STRING -> 7\n"
               "STRUCTURE -> 8 |\n");
        printf("Saisir le numero associer au type de la colnne %d : ", j);
        scanf(" %d", (int*)&tab[j]);
    }
    CDATAFRAME *cdf = create_cdataframe(tab, size);
    printf("----------------------------\n");
    int nb;
    lnode *tmp = cdf->head;
    for (int k = 0; k < size; k++) {
        printf("Saisir taille de la colnne %d : ", k);
        scanf(" %d", &nb);
        for (int j = 0; j < nb; j++) {
            void *x = NULL;
            switch (((COLUMN *)(tmp->data))->column_type) {
                case UINT:
                    x = malloc(sizeof(unsigned int));
                    printf("Valeur a ajouter a la colonne \"%s\" de type UNSIGNED INT: ", ((COLUMN *)(tmp->data))->title);
                    scanf(" %u", (unsigned int *)x);
                    break;

                case INT:
                    x = malloc(sizeof(int));
                    printf("Valeur a ajouter a la colonne \"%s\" de type INT: ", ((COLUMN *)(tmp->data))->title);
                    scanf(" %d", (int *)x);
                    break;

                case CHAR:
                    x = malloc(sizeof(char));
                    printf("Valeur a ajouter a la colonne \"%s\" de CHAR: ", ((COLUMN *)(tmp->data))->title);
                    scanf(" %c", (char *)x);
                    break;

                case FLOAT:
                    x = malloc(sizeof(float));
                    printf("Valeur a ajouter a la colonne \"%s\" de type FLOAT: ", ((COLUMN *)(tmp->data))->title);
                    scanf(" %f", (float *)x);
                    break;

                case DOUBLE:
                    x = malloc(sizeof(double));
                    printf("Valeur a ajouter a la colonne \"%s\" de type DOUBLE: ", ((COLUMN *)(tmp->data))->title);
                    scanf(" %lf", (double *)x);
                    break;

                case STRING:
                    x = malloc(256 * sizeof(char));
                    printf("Valeur a ajouter a la colonne \"%s\" de type STRING: ", ((COLUMN *)(tmp->data))->title);
                    scanf(" %s", (char *)x);
                    break;

                default:
                    printf("Type inconnu pour la colonne \"%s\"\n", ((COLUMN *)(tmp->data))->title);
                    break;
            }
            insert_value(tmp->data, x);
            free(x);
        }
        tmp = tmp->next;
    }
    return cdf;
}

void ajout_col_cdf(CDATAFRAME * cdf, COLUMN *col) {
    lnode * tmp = lst_create_lnode(col);
    lst_insert_tail((list *)cdf, tmp);
}

void changer_nom_col(CDATAFRAME * cdf, char * col_name){
    lnode *tmp = cdf->head;
    COLUMN *col;
    while(tmp != NULL){
        col = tmp->data;
        if (strcmp(col_name, col->title) == 0){
            char * str = (char *)malloc(sizeof(char)*strlen(col->title));
            printf("Saisir nouveaux nom : ");
            scanf("%s", str);
            col->title = realloc(col->title, strlen(str));
            strcpy(col->title, str);
            printf("Changement EFFECTUE\n");
            return;
        }
        tmp = tmp->next;
    }
}

int cherche_valeur(CDATAFRAME * cdf, void * x, ENUM_TYPE type){
    if (cdf==NULL || cdf->head==NULL){
        printf("Cdataframe vide\n");
        return 0;
    }
    lnode * tmp;
    tmp = cdf->head;
    while (tmp!=NULL){
        COLUMN * col = tmp->data;
        if (type == col->column_type){
            int i=0;
            while(i<col->size){
                switch (col->column_type) {
                    case UINT:
                        if (*(unsigned int*)(col->data[i]) == *(unsigned int*)x)
                            return 1;
                        break;

                    case INT:
                        if (*(int*)(col->data[i]) == *(int*)x)
                            return 1;
                        break;

                    case CHAR:
                        if (*(char*)(col->data[i]) == *((char*)x))
                            return 1;
                        break;

                    case FLOAT:
                        if (*(float*)(col->data[i]) == *(float*)x)
                            return 1;
                        break;

                    case DOUBLE:
                        if (*(double*)(col->data[i]) == *(double*)x)
                            return 1;
                        break;

                    case STRING:
                        if (strcmp((char*)col->data[i], (char*)x) == 0)
                            return 1;
                        break;

                    default:
                        break;
                }
                i++;
            }
        }
        tmp = tmp->next;
    }
    return 0;
}

int* accecder_val(CDATAFRAME * cdf, void * x, ENUM_TYPE type){
    if (cdf==NULL || cdf->head==NULL){
        printf("Cdataframe vide\n");
        return 0;
    }
    int * tab = (int*) malloc(sizeof(int)*2);
    tab[0]=-1;
    tab[1]=-1;
    int cord=0;
    lnode * tmp;
    tmp = cdf->head;
    while (tmp!=NULL){
        COLUMN * col = tmp->data;
        if (type == col->column_type){
            int i=0;
            while(i<col->size){
                switch (col->column_type) {
                    case UINT:
                        if (*(unsigned int*)(col->data[i]) == *(unsigned int*)x) {
                            tab[0] = i;
                            tab[1] = cord;
                            return tab;
                        }
                        break;

                    case INT:
                        if (*(int*)(col->data[i]) == *(int*)x) {
                            tab[0] = i;
                            tab[1] = cord;
                            return tab;
                        }
                        break;

                    case CHAR:
                        if (*(char*)(col->data[i]) == *((char*)x)) {
                            tab[0] = i;
                            tab[1] = cord;
                            return tab;
                        }
                        break;

                    case FLOAT:
                        if (*(float*)(col->data[i]) == *(float*)x) {
                            tab[0] = i;
                            tab[1] = cord;
                            return tab;
                        }
                        break;

                    case DOUBLE:
                        if (*(double*)(col->data[i]) == *(double*)x) {
                            tab[0] = i;
                            tab[1] = cord;
                            return tab;
                        }
                        break;

                    case STRING:
                        if (strcmp((char*)col->data[i], (char*)x) == 0) {
                            tab[0] = i;
                            tab[1] = cord;
                            return tab;
                        }
                        break;

                    default:
                        break;
                }
                i++;
            }
        }
        tmp = tmp->next;
        cord++;
    }
    return NULL;
}

void afficehr_nom(CDATAFRAME * cdf){
    if (cdf==NULL || cdf->head==NULL){
        printf("Cdataframe vide\n");
        return ;
    }
    lnode * tmp;
    tmp = cdf->head;
    int i=0;
    while (tmp!=NULL){
        printf("Colonne %d : %s\n",i, ((COLUMN *)(tmp->data))->title);
        tmp = tmp->next;
        i++;
    }
}

