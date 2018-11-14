//
// Created by cheva on 13/11/2018.
//

#ifndef MODULE4_DONNEES_H
#define MODULE4_DONNEES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct donnees Donnees;                 //definition de notre strucuture de donnees
struct donnees{
    int milli;
    int pouls;
};
void ecritureCSV(FILE *fichier,unsigned int nb_line, Donnees *tab);
#endif
