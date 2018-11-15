//
// Created by cheva on 13/11/2018.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
void menu(int choix, int nb_line, struct Donnees *tab){

    printf("---Menu---");
    printf("1. Afficher les donnees obtenu");
    printf("2. Afficher les donnees par ordre croissant selon le temps\n");
    printf("3. Afficher les donnees par ordre croissant selon le pouls\n");
    printf("4. Afficher les donnees par ordre decroissant selon le temps\n");
    printf("5. Afficher les donnees par ordre decroissant selon le pouls\n");
    printf("6. Afficher la frequence cardiaque pour un temps t\n");
    printf("7. Afficher la moyenne de la frequence cardiaque entre un instant t1 et t2\n");
    printf("8. Afficher le nombre de ligne en mémoire\n");
    printf("9. Afficher la frequence cardiaque maximum\n");
    printf("10. Afficher la frequence cardiaque minimum\n");    // +++ Temps associé
    printf("0. Quitter\n");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            donneesBrut(nb_line, tab);
            break;
        case 2:
            ordreCroissantTemps();
            break;
        case 3:
            ordreCroissantPouls();
            break;
        case 4:
            ordreDecroissantTemps();
            break;
        case 5:
            ordreDecroissantPouls();
            break;
        case 6:
            rechercheFrequence();
            break;
        case 7:
            moyenne(); //Ok
            break;
        case 8:
            nombreLigne();
            break;
        case 9:
            max();   //OK
            break;
        case 10:
            mini();  //OK
            break;
        case 0:
            exit(-1);
        default:
            printf("Erreur, veuillez choisir une option valide");
            break;
    }
}
