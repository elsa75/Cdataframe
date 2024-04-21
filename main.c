#include "fonctions.h"


int main() {
    COLUMN ** Cdata = create_CDataframe();
    Cdata = saisie_dur_CDataframe(Cdata);
    delete_column(*Cdata);
    print_CDataframe(Cdata, 2);
    printf("d");
    return 0;
}

