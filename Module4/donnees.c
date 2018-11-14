//
// Created by cheva on 13/11/2018.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

typedef struct donnees Donnees;
    struct donnees{
        int *milli;
        int *pouls;
    };
void lectureCSV(int *counter){
    counter = 0;
    Donnees milli;
    Donnees pouls;
                                                                        //compte le nb de ligne
    int c;                                                             //sert à regarder chaque caracère du fichier
    int nb_line = 0;
    FILE *fp;                                               // j'ouvre le fichier que je désire en mode "r"
    while ((c = getc(fp)) != EOF){
        if (c == '\n')
            ++nb_line==&counter;
    }                                                                      //fin compte ligne

    FILE* fichier = NULL;                                                 //charger info.csv

    fichier = fopen("info.csv", "r");

    if (fichier != NULL) {
        while(nb_line!=0){
            fscanf(fichier, "%d;%d ",&milli,&pouls);
            --nb_line;
}

void insertion(){

}

void inverseInsertion(){        //ordre decroissant

}

void dichotomie(){

}

