//
// Created by cheva on 13/11/2018.
//
#include <stdio.h>
#include "menu.h"
void menu(){
    int choix;
    printf("---Menu---");
    printf("1. Afficher les donnees obtenu");
    printf("2. Afficher les donnees par ordre croissant");
    printf("3. Afficher les donnees par ordre decroissant");
    printf("4. Afficher la frequence cardiaque pour un temps t");
    printf("5. Afficher la moyenne de la frequence cardiaque entre un instant t1 et t2");
    printf("6. Afficher le nombre de ligne en mémoire");
    printf("7. Afficher la frequence cardiaque maximum");
    printf("8. Afficher la frequence cardiaque minimum");    // +++ Temps associé
    printf("0. Quitter");
    scanf("%d",choix);
    switch(choix){
        case 1:
            donneesBrut();
            break;
        case 2:
            ordreCroissant();
            break;
        case 3:
            ordreDecroissant();
            break;
        case 4:
            rechercheFrequence();
            break;
        case 5:
            moyenne();
            break;
        case 6:
            nombreLigne();
            break;
        case 7:
            max();
            break;
        case 8:
            mini();
            break;
        case 0:
            return 0;
        default:
            printf("Erreur, veuillez choisir une option valide");
            break;



    }
}
