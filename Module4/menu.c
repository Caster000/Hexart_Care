#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void menu(int choix, int nb_line, struct Donnees *tab){
//---------------------------------------------Affichage du menu----------------------------------------------------
    printf("---Menu---\n");
    printf("1. Afficher les donnees obtenu\n");
    printf("2. Afficher les donnees par ordre croissant selon le temps\n");
    printf("3. Afficher les donnees par ordre croissant selon le pouls\n");
    printf("4. Afficher les donnees par ordre decroissant selon le temps\n");
    printf("5. Afficher les donnees par ordre decroissant selon le pouls\n");
    printf("6. Afficher la frequence cardiaque pour un temps t\n");
    printf("7. Afficher la moyenne de la frequence cardiaque entre un instant t1 et t2\n");
    printf("8. Afficher le nombre de ligne en mémoire\n");
    printf("9. Afficher la frequence cardiaque maximum\n");
    printf("10. Afficher la frequence cardiaque minimum\n");
    printf("0. Quitter\n");
    scanf("%d", &choix);                                                 //demande du choix
    int frequence = 0;
    int borne1 = 0;
    int borne2 = 0;
    switch (choix) {
        case 1:
            donneesBrut(nb_line, tab);                                  //afficher les donnees tel quel
            break;
        case 2:
            ordreCroissantTemps(nb_line, tab);                          //afficher en ordre croissant selon temps
            break;
        case 3:
            ordreCroissantPouls(nb_line, tab);                          //afficher en ordre croissant selon pouls
            break;
        case 4:
            ordreDecroissantTemps(nb_line, tab);                        //afficher en ordre decroissant selon temps
            break;
        case 5:
            ordreDecroissantPouls(nb_line, tab);                        //afficher en ordre decroissant selon pouls
            break;
        case 6:
            printf("Pour quel temps voulez vous le pouls ?\nDonnez le temps en millisecondes. ex: \"1000\" ou \"2000\" \n"); //afficher frequence demandé
            scanf("%d", &frequence);
            rechercheFrequence(nb_line, tab, frequence);
            break;
        case 7:
            printf("Definir la premiere borne\nDonnez le temps en millisecondes, ex: \"1000\" ou \"2000\" \n");                      //afficher moyenne entre deux bornes
            scanf(" %d", &borne1);
            printf("Definir la seconde borne\nDonnez le temps en millisecondes, ex: \"1000\" ou \"2000\" \n");
            scanf(" %d", &borne2);
            moyenne(nb_line, tab, borne1, borne2);
            break;
        case 8:
            printf("Le nombre de ligne est %d\n", nb_line);             //afficher nombre ligne
            break;
        case 9:
            max(nb_line, tab);                                          //afficher pouls maximum
            break;
        case 10:
            mini(nb_line, tab);                                         //afficher pouls minimum
            break;
        case 0:                                                         //quitter
            exit(-1);
        default:
            printf("Erreur, veuillez choisir une option valide\n");
            break;
    }

}

