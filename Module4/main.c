#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnees.h"
#include "actions.h"

int main() {
    int choix=-1;
      int nb_line=0;
   struct Donnees *tab;                                      //creation de notre tableau de structure
//------------------------------------------définition du fichier à utiliser-------------------------------------------
    FILE* fichier = NULL;

    if((fichier = fopen("info.csv", "r")) == NULL) {                     //chargement de info.csv
        printf("\n---Impossible d'ouvrir -> info.csv.---\n");           //message d'erreur si pas de fichier
        exit(-1);
    }

//--------------------------------------------------compte le nombre de lignes-------------------------------------------------------
  int c;                                                    //sert à regarder chaque caracère du fichier
  while ((c = fgetc(fichier)) != EOF){                      //EOF ---> End of File
      if (c == '\n')                                        // \n correspond a un char, donc à un entier.
          ++nb_line;
  } //----------------------------------fin compte lignes--------------------------------------
    rewind(fichier);                                        //remise du curseur au début


 //--------------------------------------allocation du tableau de donnée avec une taille dynamique selon nb_line------------------
    if((tab = malloc(nb_line * sizeof(struct Donnees))) == NULL)
    {
        printf("\n---Unable to allocate space for tableau_data.---\n");    
        exit(-1);
    }
//-----------------------------------utilisation des fonctions-------------------------------------------------------------
    ecritureCSV(fichier,nb_line, tab);
    menu(choix, nb_line, tab);


    free(tab);                          //liberation memoire de malloc
    fclose(fichier);                    //fermeture du fichier
  return 0;
}
