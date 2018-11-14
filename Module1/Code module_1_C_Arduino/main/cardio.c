#include"cardio.h"
#include<Arduino.h>

unsigned long time;

int temps(){
    time = millis();
    return(time);
  }

int calculBattement(int battement){ 
    battement++;
    delay(70);
    return(battement);
  }


int calculPouls(int battement){
     int pouls = 4*battement;
     return(pouls);
  }


    
                
  
