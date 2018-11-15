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

}

void nombreLigne(){

}

void max(){

}

void mini(){

}

