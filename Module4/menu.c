//
// Created by cheva on 13/11/2018.
//
#include <stdio.h>
#include "menu.h"
void menu(int choix){

    printf("---Menu---");
    printf("1. Afficher les donnees obtenu");
    printf("2. Afficher les donnees par ordre croissant selon le temps");
    printf("3. Afficher les donnees par ordre croissant selon le pouls");
    printf("4. Afficher les donnees par ordre decroissant selon le temps");
    printf("5. Afficher les donnees par ordre decroissant selon le pouls");
    printf("6. Afficher la frequence cardiaque pour un temps t");
    printf("7. Afficher la moyenne de la frequence cardiaque entre un instant t1 et t2");
    printf("8. Afficher le nombre de ligne en mémoire");
    printf("9. Afficher la frequence cardiaque maximum");
    printf("10. Afficher la frequence cardiaque minimum");    // +++ Temps associé
    printf("0. Quitter");
    scanf("%d",choix);
    switch(choix){
        case 1:
            donneesBrut();
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
            moyenne();
            break;
        case 8:
            nombreLigne();
            break;
        case 9:
            max();
            break;
        case 10:
            mini();
            break;
        case 0:
            return 0;
        default:
            printf("Erreur, veuillez choisir une option valide");
            break;
    }
}
