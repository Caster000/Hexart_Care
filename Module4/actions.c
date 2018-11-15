#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

//---------------------------------afficher les donnees tel quel----------------------------------------------
void donneesBrut( int nb_line, struct Donnees *tab){
     int i;
    for (i=0;i<nb_line;i++){                                            //permet d'afficher tout le fichier
        printf("%d;%d\n", tab[i].milli, tab[i].pouls);
    }

}
//---------------------------------afficher en ordre croissant selon temps----------------------------------------------
void ordreCroissantTemps(int nb_line, struct Donnees *tab){
    int i,j;
    struct Donnees tmp,tmp1;
    i=0;
    j=0;

    for (i=0;i<nb_line;i++)                                             //permet de lire tout le fichier
    {
        for(j=i;j<nb_line;j++)                                          //tri à bulle
        {
            if(tab[j].milli<tab[i].milli)                               //permet echanger les valeurs de 2 indices tab[].milli
            {
                tmp.milli=tab[i].milli;
                tab[i].milli=tab[j].milli;
                tab[j].milli=tmp.milli;

                tmp1.pouls=tab[i].pouls;                               //permet echanger les valeurs de 2 indices tab[].poul
                tab[i].pouls=tab[j].pouls;
                tab[j].pouls=tmp1.pouls;
            }
        }
    }
    for(i=0;i<nb_line;i++)
    {
        printf("%d;%d \n",tab[i].milli, tab[i].pouls);
    }
}
//---------------------------------afficher en ordre croissant selon pouls----------------------------------------------
void ordreCroissantPouls(int nb_line, struct Donnees *tab){
    int i,j;
    struct Donnees tmp,tmp1;
    i=0;
    j=0;

    for (i=0;i<nb_line;i++)                                         //permet de lire tout le fichier
    {
        for(j=i;j<nb_line;j++)                                      //tri à bulle
        {
            if(tab[j].pouls<tab[i].pouls)
            {
                tmp.pouls=tab[i].pouls;                               //permet echanger les valeurs de 2 indices tab[].pouls
                tab[i].pouls=tab[j].pouls;
                tab[j].pouls=tmp.pouls;

                tmp1.milli=tab[i].milli;                               //permet echanger les valeurs de 2 indices tab[].milli
                tab[i].milli=tab[j].milli;
                tab[j].milli=tmp1.milli;
            }
        }
    }
    for(i=0;i<nb_line;i++)
    {
        printf("%d;%d \n",tab[i].milli, tab[i].pouls);
    }
}
//---------------------------------afficher en ordre decroissant selon temps----------------------------------------------
void ordreDecroissantTemps(int nb_line, struct Donnees *tab){
    int i,j;
    struct Donnees tmp,tmp1;
    i=0;
    j=0;

    for (i=0;i<nb_line;i++)                                         //permet de lire tout le fichier
    {
        for(j=i;j<nb_line;j++)                                      //tri à bulle
        {
            if(tab[j].milli>tab[i].milli)
            {
                tmp.milli=tab[i].milli;                               //permet echanger les valeurs de 2 indices tab[].milli
                tab[i].milli=tab[j].milli;
                tab[j].milli=tmp.milli;

                tmp1.pouls=tab[i].pouls;                               //permet echanger les valeurs de 2 indices tab[].pouls
                tab[i].pouls=tab[j].pouls;
                tab[j].pouls=tmp1.pouls;
            }
        }
    }
    for(i=0;i<nb_line;i++)                                         //permet d'afficher tout le fichier
    {
        printf("%d;%d \n",tab[i].milli, tab[i].pouls);
    }
}
//---------------------------------afficher en ordre decroissant selon pouls----------------------------------------------
void ordreDecroissantPouls(int nb_line, struct Donnees *tab){

    int i,j;
    struct Donnees tmp,tmp1;
    i=0;
    j=0;

    for (i=0;i<nb_line;i++)                                         //permet de lire tout le fichier
    {
        for(j=i;j<nb_line;j++)                                      //tri à bulle
        {
            if(tab[j].pouls>tab[i].pouls)
            {
                tmp.pouls=tab[i].pouls;                               //permet echanger les valeurs de 2 indices tab[].pouls
                tab[i].pouls=tab[j].pouls;
                tab[j].pouls=tmp.pouls;

                tmp1.milli=tab[i].milli;                               //permet echanger les valeurs de 2 indices tab[].milli
                tab[i].milli=tab[j].milli;
                tab[j].milli=tmp1.milli;
            }
        }
    }
    for(i=0;i<nb_line;i++)                                         //permet d'afficher tout le fichier
    {
        printf("%d;%d \n",tab[i].milli, tab[i].pouls);
    }
}
//---------------------------------afficher frequence demandé----------------------------------------------
void rechercheFrequence(int nb_line, struct Donnees *tab, int frequence){
int i;
    for(i=0;i<nb_line;i++){                                        //permet de lire tout le fichier
        if(tab[i].pouls==frequence){
            printf("%d;%d", tab[i].milli, tab[i].pouls);
        }
    }
}
//---------------------------------afficher moyenne entre deux bornes----------------------------------------------
void moyenne(int nb_line, struct Donnees *tab, int borne1, int borne2){
    float total_pouls = 0;
    float nb_valeur = 0;
    int temporaire = 0;
    int i = 0;

    for(temporaire = borne1; temporaire <= borne2; temporaire += TEMPS)
    {
        for(i=0; i<nb_line; i++)                                    //permet de lire tout le fichier
        {
            if(tab[i].milli == temporaire)
            {
                total_pouls += tab[i].pouls;                        //additionne valeurs entre les bornes
                nb_valeur++;
            }
        }
    }
    printf("\nLa moyenne de pouls sur l'intervalle %d - %d est de %f", borne1, borne2, (total_pouls/nb_valeur));
}
//---------------------------------afficher pouls maximum----------------------------------------------
void max(int nb_line, struct Donnees *tab){
    int id_min = 0;
    int id_max = 0;

    int i = 0;
    for(i=0; i < nb_line; i++)                                         //permet de lire tout le fichier
    {
        if(tab[id_min].pouls > tab[i].pouls)                          //compare toutes les valeurs
        {
            id_min = i;
        }
        if(tab[id_max].pouls < tab[i].pouls)
        {
            id_max = i;
        }
    }
    printf("Le pouls maximum est %d\n",tab[id_max].pouls);
}
//---------------------------------afficher pouls minimum----------------------------------------------
void mini(int nb_line, struct Donnees *tab){
    int id_min = 0;
    int id_max = 0;

    int i = 0;
    for(i=0; i < nb_line; i++)                                         //permet de lire tout le fichier
    {
        if(tab[id_min].pouls > tab[i].pouls)                          //compare toutes les valeurs
        {
            id_min = i;
        }
        if(tab[id_max].pouls < tab[i].pouls)
        {
            id_max = i;
        }
    }
    printf("Le pouls minimum est %d\n",tab[id_min].pouls);
}

