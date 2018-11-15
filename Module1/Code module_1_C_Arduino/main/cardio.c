#include"cardio.h"
#include<Arduino.h>

unsigned long time;

int temps(){                      //calcul le temps total du programme
  
    ++time;
    return(time);
  }

int calculBattement(int battement){                   //incrementation pour le nombre de battement
    battement++;
    delay(70);                                        //delai symbolisant la fin de la variation d'un battement
    return(battement);
  }


int calculPouls(int battement){                       
     int pouls = 4*battement;                         //on calcul pour avoir le pouls par minute
     return(pouls);
  }


    
                
  
