lien github : https://github.com/elsa75/Cdataframe.git
Parcours choisi : Colonnes du tout type de données
                  Cdataframe est une liste doublement chainée
                  Fonctionnalités basique car manque de temps malheureusment

Pour l'utilisation du code il suffit le lancer le code, il y a le menu, pas d'autre instruction nécessaires

Les fonctions les plus importante sont :
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);   -> Crée le cdataframe vide
void delete_cdataframe(CDATAFRAME **cdf);                      -> Supprime le cdaframe
void delete_column_cdf(CDATAFRAME *cdf, char *col_name);       -> Supprime une colonne
void print_cdataframe(CDATAFRAME * cdf);                       -> Affiche le Cdataframe
CDATAFRAME * create_cdataframe_saisi();                        -> Crée le Cdataframe en dur
void ajout_col_cdf(CDATAFRAME * cdf, COLUMN* col);             -> Ajoute une colonne
void changer_nom_col(CDATAFRAME * cdf, char * col_name);       -> Change le nom des colonnes
int* accecder_val(CDATAFRAME * cdf, void * x, ENUM_TYPE type); ->Renvoie les coordonée d'une valeur
void afficehr_nom(CDATAFRAME * cdf);                           -> Affiche le nom des colonnes  

Pour le reste les fonctions tout est expliqué plus précisement dans le code directement
