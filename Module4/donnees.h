#ifndef MODULE4_DONNEES_H
#define MODULE4_DONNEES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

                //definition de notre strucuture de donnees
struct Donnees{
    int milli;
    int pouls;
};
void ecritureCSV(FILE *fichier, int nb_line, struct Donnees *tab);
#endif
