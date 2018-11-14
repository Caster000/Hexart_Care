#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"
#
int main() {
int i;

    Donnees *tab = NULL;                //creation de ,notre tableau de structure

    FILE* fichier = NULL;

    if((fichier = fopen("info.csv", "r")) == NULL) {                    //charger info.csv
        printf("\n---Impossible d'ouvrir -> info.csv.---\n");           //message d'erreur si pas de fichier
        exit(-1);
    }
    unsigned  int nb_line;


                         //compte le nb de ligne
  int c;                                                   //sert à regarder chaque caracère du fichier
  FILE *fp;                                               // j'ouvre le fichier que je désire en mode "r"
  while ((c = getc(fp)) != EOF){
      if (c == '\n')                                        // \n correspond a un char, donc à un entier.
          ++nb_line;
  }                                                                      //fin compte ligne
    rewind(fichier);//remise au cursuer au début


    //allocation du tableau de donnée avec une taille dynamique selon nb_line
    if((tab = malloc(nb_line * sizeof(Donnees))) == NULL)
    {
        printf("\n---Unable to allocate space for tableau_data.---\n");
        exit(-1);
    }
    ecritureCSV(fichier,nb_line, tab);
    menu(choix);
  return 0;
}
