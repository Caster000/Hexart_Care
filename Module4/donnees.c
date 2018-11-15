#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

//--------------------------------------------fonction d'ecriture du fichier dans structure-------------------------------------------------
void ecritureCSV(FILE *fichier, int nb_line,struct Donnees *tab){                     //stock le fichier dans notre tableau de structcure
    int i=0;
    if (fichier != NULL) {
        for(i=0;i!=nb_line; i++) {
            fscanf(fichier, "%d;%d\n ", &tab[i].milli, &tab[i].pouls);
        }
    }
}



