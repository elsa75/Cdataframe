#ifndef CDATAFRAME_FONCTIONS_H
#define CDATAFRAME_FONCTIONS_H
#define REALOC_SIZE 256
#include <string.h>
#include <stdlib.h>
#include <stdio.h>





typedef struct{
    char titre[20];
    int taille_physique;
    int taille_logique;
    int * donnees;
}COLUMN;


COLUMN * create_column(char* title); /** Crée une colonne **/
int insert_value( COLUMN * mycol, int val ); /** Insert une valeur dans une colonne **/
void delete_column(COLUMN *col); /** Supprimme une colonne **/
void print_col(COLUMN* col); /** Affiche une colonne **/
int nb_occurrences(COLUMN *col, int val); /** Renvoi le nombre d'occurence d'une valeur dans une colonne **/
int val_precedent(COLUMN *col, int pos); /** Renvoi la valeur précédente à un indice donné dans une colonne**/
int nb_val_sup(COLUMN *col, int val); /** Renvoi le nombre de valeur supérieur à une valeur dans une colonne **/
int nb_val_inf(COLUMN *col, int val); /** Renvoi le nombre de valeur inférieur à une valeur dans une colonne **/


COLUMN ** create_CDataframe(); /** Crée un CDataframe **/
void saisie_CDataframe( COLUMN ** cd, int taille_tab); /** Permet de remplir un CDataframe a clavier **/
COLUMN ** saisie_dur_CDataframe(COLUMN ** cd); /** Permet de remplir un CDataframe en dur **/
void print_CDataframe(COLUMN ** cd, int taille);
void print_colones_x(COLUMN ** cd, int taille, int val);
void print_lignes_x(COLUMN ** cd, int taille, int val);
void ajout_ligne_CDataframe(COLUMN ** cd, int taille);

#endif
