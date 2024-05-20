#include "fonctions.h"
#include "cdataframe.h"

int main(){
    CDATAFRAME *cdf = NULL;
    int choix;
    printf("\nBienvenue dans le programme CDataFrame !\n");

    do {
        COLUMN * col = NULL;
        int size = 0;
        char str[20];
        int type = 0;
        int nb = 0;
        void * x=NULL;
        int verif = 0;
        printf("\nMenu Principal:\n");
        printf("-------------------------------------------------\n");
        printf("  [1] Créer un CDataFrame vide\n");
        printf("  [2] Créer un CDataFrame dur\n");
        printf("  [3] Créer un CDataFrame par saisie\n");
        printf("  [4] Ajouter une ligne\n");
        printf("  [5] Ajouter une colonne\n");
        printf("  [6] Obtenir le nombre de colonne du CDataFrame\n");
        printf("  [7] Changer le nom d'une colonne\n");
        printf("  [8] Accéder à une valeur\n");
        printf("  [9] Chercher une valeur\n");
        printf(" [10] Supprimer un CDataFrame\n");
        printf(" [11] Supprimer une colonne\n");
        printf(" [12] Afficher le CDataFrame\n");
        printf(" [13] Afficher le CDataframe à partir d'une ligne\n");
        printf(" [14] Afficher le CDataframe à partir d'un colonne\n");
        printf(" [15] Afficher les noms des colonnes\n");
        printf("  [0] Quitter\n");
        printf("-------------------------------------------\n");
        printf("Votre choix: ");
        scanf(" %d", &choix);

        switch (choix) {
            case 1:
                printf("De quelle taille souhaitez vous le Cdataframe ?\n-> ");
                scanf(" %d",&size);
                ENUM_TYPE * tab = (ENUM_TYPE*) malloc(sizeof(ENUM_TYPE)*size);
                for (int i=0;i<size;i++) {
                    printf("UNIT -> 2      | INT -> 3    | CHAR -> 4\n"
                           "FLOAT -> 5     | DOUBLE -> 6 | STRING -> 7\n"
                           "STRUCTURE -> 8 |\n"
                           "De quelle type sera votre colonne %d : ", i + 1);
                    scanf(" %d", &(tab[i]));
                }
                cdf = create_cdataframe(tab, size);
                printf("\nsucces");
                break;
            case 2:
                cdf = create_cdataframe_dur();
                printf("succes");
                break;
            case 3:
                cdf = create_cdataframe_saisi();
                printf("\n");
                printf("succes");
                break;
            case 4:
                ajouter_ligne_cdf(cdf);
                printf("\n");
                printf("succes");
                break;
            case 5:
                col = create_column_saisie();
                ajout_col_cdf(cdf, col);
                printf("\n");
                printf("succes");
                break;
            case 6:
                printf("Il y a %d colonnes dans le Cdataframe",get_cdataframe_cols_size(cdf));
                printf("\n");
                printf("succes");
                break;
            case 7:
                afficehr_nom(cdf);
                printf("Saisir le nom d'une colonne à changer : ");
                scanf(" %s", str);
                changer_nom_col(cdf, str);
                printf("\n");
                printf("succes");
                break;
            case 8:
                printf("UNIT -> 0      | INT -> 1    | CHAR -> 2\n"
                       "FLOAT -> 3     | DOUBLE -> 4 | STRING -> 5\n"
                       "STRUCTURE -> 6 |\n"
                       "De quelle type sera votre valeur : ");
                scanf(" %d", &type);
                switch (type){
                    case 0:
                        x = malloc(sizeof(unsigned int));
                        printf("Valeur a chercher a la colonne de type UNSIGNED INT: ");
                        scanf("%u", (unsigned int*)x);
                        printf("Ligne %d | Colonne %d",(accecder_val(cdf, x,UINT))[0],(accecder_val(cdf, x,UINT))[0] );
                        break;
                    case 1:
                        x = malloc(sizeof(int));
                        printf("Valeur a chercher a la colonne de type INT: ");
                        scanf("%d", (int*)x);
                        printf("Ligne %d | Colonne %d",(accecder_val(cdf, x,INT))[0],(accecder_val(cdf, x,INT))[0] );
                        break;
                    case 2:
                        x = malloc(sizeof(char));
                        printf("Valeur a chercher a la colonne de type CHAR: ");
                        scanf(" %c", (char*)x);
                        printf("Ligne %d | Colonne %d",(accecder_val(cdf, x,CHAR))[0],(accecder_val(cdf, x,CHAR))[0] );
                        break;
                    case 3:
                        x = malloc(sizeof(float));
                        printf("Valeur a chercher a la colonne de type FLOAT: ");
                        scanf("%f", (float*)x);
                        printf("Ligne %d | Colonne %d",(accecder_val(cdf, x,FLOAT))[0],(accecder_val(cdf, x,FLOAT))[0] );
                        break;
                    case 4:
                        x = malloc(sizeof(double));
                        printf("Valeur a chercher a la colonne de type DOUBLE: ");
                        scanf("%lf", (double*)x);
                        printf("Ligne %d | Colonne %d",(accecder_val(cdf, x,DOUBLE))[0],(accecder_val(cdf, x,DOUBLE))[0] );
                        break;
                    case 5:
                        x = malloc(20 * sizeof(char));
                        printf("Valeur a chercher a la colonne de type STRING: ");
                        scanf("%s", (char*)x);
                        printf("Ligne %d | Colonne %d",(accecder_val(cdf, x,STRING))[0],(accecder_val(cdf, x,STRING))[0] );
                        break;
                    default:
                        printf("Type impossible\n");
                        break;
                }
                printf("\n");
                printf("succes");
                break;
            case 9:
                printf("UNIT -> 0      | INT -> 1    | CHAR -> 2\n"
                       "FLOAT -> 3     | DOUBLE -> 4 | STRING -> 5\n"
                       "STRUCTURE -> 6 |\n"
                       "De quelle type sera votre valeur : ");
                scanf(" %d", &type);
                switch (type){
                    case 0:
                        x = malloc(sizeof(unsigned int));
                        printf("Valeur a chercher a la colonne de type UNSIGNED INT: ");
                        scanf("%u", (unsigned int*)x);
                        verif = cherche_valeur(cdf, x, UINT);
                        if (verif)
                            printf("La valeur existe dans le CDatadrame");
                        else
                            printf("La valeur n'existe pas dans le CDataframe");
                        break;
                    case 1:
                        x = malloc(sizeof(int));
                        printf("Valeur a chercher a la colonne de type INT: ");
                        scanf("%d", (int*)x);
                        verif = cherche_valeur(cdf, x, INT);
                        if (verif)
                            printf("La valeur existe dans le CDatadrame");
                        else
                            printf("La valeur n'existe pas dans le CDataframe");
                        break;
                    case 2:
                        x = malloc(sizeof(char));
                        printf("Valeur a chercher a la colonne de type CHAR: ");
                        scanf(" %c", (char*)x);
                        verif = cherche_valeur(cdf, x, CHAR);
                        if (verif)
                            printf("La valeur existe dans le CDatadrame");
                        else
                            printf("La valeur n'existe pas dans le CDataframe");
                        break;
                    case 3:
                        x = malloc(sizeof(float));
                        printf("Valeur a chercher a la colonne de type FLOAT: ");
                        scanf("%f", (float*)x);
                        verif = cherche_valeur(cdf, x, FLOAT);
                        if (verif)
                            printf("La valeur existe dans le CDatadrame");
                        else
                            printf("La valeur n'existe pas dans le CDataframe");
                        break;
                    case 4:
                        x = malloc(sizeof(double));
                        printf("Valeur a chercher a la colonne de type DOUBLE: ");
                        scanf("%lf", (double*)x);
                        verif = cherche_valeur(cdf, x, DOUBLE);
                        if (verif)
                            printf("La valeur existe dans le CDatadrame");
                        else
                            printf("La valeur n'existe pas dans le CDataframe");
                        break;
                    case 5:
                        x = malloc(20 * sizeof(char));
                        printf("Valeur a chercher a la colonne de type STRING: ");
                        scanf("%s", (char*)x);
                        verif = cherche_valeur(cdf, x, STRING);
                        if (verif)
                            printf("La valeur existe dans le CDatadrame");
                        else
                            printf("La valeur n'existe pas dans le CDataframe");
                        break;
                    default:
                        printf("Type impossible\n");
                        break;
                }
                printf("\n");
                printf("succes");
                break;
            case 10:
                delete_cdataframe(&cdf);
                printf("\n");
                printf("succes");
                break;
            case 11:
                afficehr_nom(cdf);
                printf("Saisir le nom de la colonne a supprimer : ");
                scanf(" %s", str);
                delete_column_cdf(cdf, str);
                printf("\n");
                printf("succes");
                break;
            case 12:
                print_cdataframe(cdf);
                printf("\n");
                printf("succes");
                break;
            case 13:
                printf("Saisir la valeur pour commencer l'affichage :");
                scanf("%d", &nb);
                printf_ligne_partir_x(cdf, nb);
                printf("\n");
                printf("succes");
                break;
            case 14:
                printf("Saisir la valeur pour commencer l'affichage :");
                scanf("%d", &nb);
                printf_col_partir_x(cdf, nb);
                printf("\n");
                printf("succes");
                break;
            case 15:
                afficehr_nom(cdf);
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
        }
    } while (choix != 0);

    return 0;
}
