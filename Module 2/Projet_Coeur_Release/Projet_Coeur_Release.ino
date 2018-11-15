#include "coeur.c"
#include "param.h"

int LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8, LED9, LED10, compteur; //Initialisation des LEDs et du compteur sous des identificateurs compréhensibles

void setup() {

pinMode(13, OUTPUT);
digitalWrite(13,HIGH);

LED1 = 2;                                                             //Début d'initialisation
LED2 = 3;
LED3 = 4;
LED4 = 5;
LED5 = 6;
LED6 = 7;
LED7 = 8;
LED8 = 9;
LED9 = 10;
LED10 = 11;                                                           //Fin initialisation des LEDs


for(compteur=LED1;compteur<=LED10;compteur++){                        //Initialisation des LEDs en tant que sortie
      pinMode(compteur,OUTPUT);
}

compteur = 1;                                                         //Initialisation du compteur servant pour les boucles

}

void loop() {
  lancement();
}                                                 //Fin loop()
