//
// Created by cheva on 13/11/2018.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "actions.h"
#include "donnees.h"




void donneesBrut( int nb_line, struct Donnees *tab){
     int i;
    for (i=0;i<nb_line;i++){
        printf("%d;%d", tab[i].milli, tab[i].pouls);
    }

}

void ordreCroissantTemps(){
 int i,j;
    int tmp=0;
    for (i=0;i<4;i++)
    {
        for(j=i;j<4;j++)
        {
            if(t[j]<t[i])
            {
                tmp=t[i];
                t[i]=t[j];
                t[j]=tmp;
            }
        }
    }
    for(i=0;i<4;i++)
    {
        printf("%d \n",t[i]);
    }

    getch();

    }
}
}

void ordreCroissantPouls(){

}

void ordreDecroissantTemps(){

}

void ordreDecroissantPouls(){

}

void rechercheFrequence(){

}

void moyenne(){
void Moyenne_pouls_plage_temps(int temps_a, int temps_b, int nombre_de_ligne, struct data *tableau_data)
{
    float total_pouls = 0;
    float nb_valeur = 0;
    int temporraire_temps = 0;
    int y = 0;

    for(temporraire_temps = temps_a; temporraire_temps < temps_b; temporraire_temps += PERIODE)
    {
        for(y=0; y < nombre_de_ligne; y++)
        {
            if(tableau_data[y].millisecondes == temporraire_temps)
            {
                total_pouls += tableau_data[y].pouls;
                nb_valeur++;
            }
        }
    }
    printf("\nLa moyenne de pouls sur l'interval %d ; %d est de %f", temps_a, temps_b, (total_pouls/nb_valeur));
}


}

void nombreLigne(){

}

void max(){
#include <stdio.h>

void Afficher_min_max(unsigned int nombre_de_ligne,struct data *tableau_data)//uniquement si il y a un seul pouls min/max
{
    int id_min = 0;
    int id_max = 0;

    unsigned int i = 0;
    for(i=0; i < nombre_de_ligne; i++)
    {
if(tableau_data[id_min]).pouls > tableau_data[i].pouls)
        {
            id_min = i;
        }
if(tableau_data[id_max].pouls < tableau_data[i].pouls)
        {
            id_max = i;
        }
    }
}


}

void mini(){

}

