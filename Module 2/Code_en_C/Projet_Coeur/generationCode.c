#include <stdio.h>
#include <stdlib.h>
#include "generationCode.h"

static int mode = 1;
static int sensibilite = 123;
static int led = 1;
static int unSurNb = 2;

int choixMode(int choix){
    mode = choix;
    return 0;
}

int choixSensibilite(int choix){
    sensibilite = choix;
    return 0;
}

int choixLED(int choix){
    led = choix;
    return 0;
}

int choixUnSurNb(int choix){
    unSurNb = choix;
    return 0;
}

int ecritureFichier(){                                          //Edite le fichier avec les param�tres entr�s

    FILE* fichier_param = NULL;                                 //Initialisation du pointeur sur fichier

    fichier_param = fopen("param.h", "w+");                       //Cr�ation et ouverture du fichier

    if(fichier_param!=NULL){                                    //V�rification du bon fonctionnement de la cr�atio et ouverture

        fputs("#ifndef PARAM_H_INCLUDED\n", fichier_param);     //D�finition des param�tres necessaires
        fputs("#define PARAM_H_INCLUDED\n", fichier_param);
        fputs("\n", fichier_param);
        fprintf(fichier_param, "#define MODE %d\n", mode);
        fprintf(fichier_param, "#define SENSIBILITE %d\n", 1023-sensibilite);
        fprintf(fichier_param, "#define LED %d\n", led);
        fprintf(fichier_param, "#define UNSURNB %d\n", unSurNb);
        fputs("\n", fichier_param);
        fputs("#endif PARAM_H_INCLUDED", fichier_param);                     //Fin de d�finition des param�tres necessaires

        if(fclose(fichier_param)!=0){
            printf("Erreur de fermeture du fichier.\n");
        }

    }else{
        printf("Erreur d'edition du fichier.\n");
    }

return 0;
}



//Definition de SENSIBILITE � faire avec 1023-SENSIBILITESAISIE
