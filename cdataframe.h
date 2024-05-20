#include "fonctions.h"
#include "list.h"
#ifndef CDATAFRAMEV3_CDATAFRAME_H
#define CDATAFRAMEV3_CDATAFRAME_H

typedef list CDATAFRAME;

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);
void delete_cdataframe(CDATAFRAME **cdf);
void delete_column_cdf(CDATAFRAME *cdf, char *col_name);
int get_cdataframe_cols_size(CDATAFRAME *cdf);
void print_cdataframe(CDATAFRAME * cdf);
void printf_col_partir_x(CDATAFRAME * cdf, int x);
void printf_ligne_partir_x(CDATAFRAME * cdf, int x);
void ajouter_ligne_cdf(CDATAFRAME * cdf);
CDATAFRAME * create_cdataframe_dur();
CDATAFRAME * create_cdataframe_saisi();
void ajout_col_cdf(CDATAFRAME * cdf, COLUMN* col);
void changer_nom_col(CDATAFRAME * cdf, char * col_name);
int cherche_valeur(CDATAFRAME * cdf, void * x, ENUM_TYPE type);
int* accecder_val(CDATAFRAME * cdf, void * x, ENUM_TYPE type);
void afficehr_nom(CDATAFRAME * cdf);

#endif //CDATAFRAMEV3_CDATAFRAME_H

