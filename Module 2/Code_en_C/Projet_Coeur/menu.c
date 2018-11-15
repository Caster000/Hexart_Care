#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "generationCode.h"

int startMenu(){

    int choixMod = 0;
    int choix = 0;

        printf("Bienvenue dans le menu de creation de fichier param.h !\n");
        printf("Celui-ci va vous permettre de configurer le coeur en LED.\n");
        printf("ATTENTION : l'operation ecrasera le fichier param.h pre-existants !\n");
        system("pause");

    do{

        system("CLS");
        printf("Par defaut, le mode d'affichage est l'allumage de toutes les LEDs a chaque battement.\n");
        printf("Par defaut, la sensibilite est reglee a 123.\n");
        printf("Veuillez taper sur :\n");
        printf("1 Pour modifier le mode d'affichage.\n");           //Définition de MODE
        printf("2 Pour modifier la sensibilite des mesures.\n");    //Définition de SENSIBILITE
        printf("Autre pour quitter.\n");

        scanf("%d", &choixMod);

        if(choixMod == 1){                                           //Début définition mode d'affichage
            do{                                                   //Boucle de vérifiant que la valeur saisie ne soit pas erronée
                system("CLS");
                printf("Par defaut, le mode d'affichage est l'allumage de toutes les LEDs a chaque battement.\n");
                printf("Les modes d'affichage possibles sont :\n");
                printf("(Tapez 1) Toutes les LEDs s'allument et s'eteignent a chaque battement de coeur.\n");
                printf("(Tapez 2) Les LEDs forment une chenille qui avance a chaque battement de coeur.\n");
                printf("(Tapez 3) Les LEDs forment une chenille qui avance a chaque battement de coeur, d'une LED sur deux.\n");
                printf("(Tapez 4) Les LEDs forment un LED-metre qui avance a chaque battement de coeur.\n");
                printf("(Tapez 5) Vous choisissez quelle LED allumer lorsque votre coeur bat.\n");
                printf("(Tapez 6) Vous choisissez la frequence de LED allumee sur le total (Une sur Deux, par exemple).\n");

                scanf("%d", &choix);                              //Choix du mode d'affichage

                if(choix<1 || choix>6){                                           //Affichage d'un message d'erreur si valeur erronée
                    printf("Valeur erronee. Veuillez taper une valeur reconnue.\n");
                    system("pause");
                }

            }while(choix<1 || choix>6);                             //Re-boucle au choix du mode si valeur erronée

            if(choixMode(choix)!=0){                    //Envoie la valeur pour écriture et vérifie si la fonction s'est terminée
                printf("Erreur d'ecriture. Veuillez recommencer votre saisie.\n");
            };

        switch(choix){                                              //Condition pour modes d'affichage demandant une paramètre

            case 5 :                                                //Mode LED unique à allumer

                do{                                                 //Re-bouclage si valeur erronée
                    system("CLS");
                    printf("Veuillez choisir la LED a allumer. [Valeur min : 1 | Valeur max : 10]\n");
                    scanf("%d", &choix);
                }while(choix<1 || choix>10);

                if(choixLED(choix)!=0){                //Envoie la valeur pour écriture et vérifie si la fonction s'est terminée
                    printf("Erreur d'ecriture. Veuillez recommencer votre saisie.\n");
                };
                break;

            case 6 :                                                //Mode d'affichage 1 LED sur NB

                do{                                                 //Re-bouclage si valeur erronée
                    system("CLS");
                    printf("Veuillez choisir la frequence de LED allumees. (1/f) [Valeur min : 1 | Valeur max : 10]\n");
                    scanf("%d", &choix);
                }while(choix<1 || choix>10);

                choixUnSurNb(choix);

                if(choixUnSurNb(choix)!=0){           //Envoie la valeur pour écriture et vérifie si la fonction s'est terminée
                    printf("Erreur d'ecriture. Veuillez recommencer votre saisie.\n");
                };
                break;

            default :
            break;

          }                                                         //Fin switch

        }                                                           //Fin définition mode d'affichage

        if(choixMod == 2){                                             //Début définition sensibilité

            do{                                                     //Re-bouclage si valeur erronée
                system("CLS");
                printf("La sensibilite defini la valeur minimale de mesure.\n");
                printf("Plus celle-ci est elevee, plus le systeme repondras.\n");
                printf("Veuillez saisir une valeur de sensibilite comprise entre 0 et 1023.\n");
                printf("[Valeur par defaut : 123]\n");

                scanf("%d", &choix);
            }while(choix<0 || choix>1023);                          //Fin du re-bouclage

            if(choixSensibilite(choix)!=0){             //Envoie la valeur pour écriture et vérifie si la fonction s'est terminée
                printf("Erreur d'ecriture. Veuillez recommencer votre saisie.\n");
            };

        }

    }while(choixMod == 1 || choixMod == 2);                                     //Re-bouclage du menu principal

    printf("Edition du fichier en cours...\n");

    if(ecritureFichier()==0){                                             //Vérification du bon fonctionnement de l'édition
        printf("Edition terminee.\n");
    }else{
        printf("Edition echouee.\n");
    }


return 0;

}

