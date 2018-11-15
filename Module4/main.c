#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

int main() {
    int choix;
      int nb_line;
   struct Donnees *tab;                //creation de notre tableau de structure

    FILE* fichier = NULL;

    if((fichier = fopen("info.csv", "r")) == NULL) {                    //tente de charger info.csv
        printf("\n---Impossible d'ouvrir -> info.csv.---\n");           //message d'erreur si pas de fichier
        exit(-1);
    }



                         //compte le nb de ligne
  int c;                                                   //sert à regarder chaque caracère du fichier
                                              // j'ouvre le fichier que je désire en mode "r"
  while ((c = fgetc(fichier)) != EOF){
      if (c == '\n')                                        // \n correspond a un char, donc à un entier.
          ++nb_line;
  }                                                                      //fin compte ligne
    rewind(fichier);//remise au curseur au début


    //allocation du tableau de donnée avec une taille dynamique selon nb_line
    if((tab = malloc(nb_line * sizeof(struct Donnees))) == NULL)
    {
        printf("\n---Unable to allocate space for tableau_data.---\n");
        exit(-1);
    }
    ecritureCSV(fichier,nb_line, tab);
    menu(choix, nb_line, tab);
  return 0;
}
