#include "cardio.c"
#include "cardio.h"
#include "coeur.c"
#include "coeur.h"
#include "param.h"
//--------------------------------------------------------------------Variables Module 1----------------------------------------------------------------------------//
long t;                            //temps
int compteur1 = 0;                 //periodicité mesure
int battement = 0;
int pouls = 0;
//--------------------------------------------------------------------Variables Module 1----------------------------------------------------------------------------//
//--------------------------------------------------------------------Variables Module 2----------------------------------------------------------------------------//
int LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8, LED9, LED10; //Initialisation des LEDs sous des identificateurs compréhensibles
int compteur;                                                    //Initialisation du compteur servant à gérer les boucles du coeur de LED
//--------------------------------------------------------------------Variables Module 2----------------------------------------------------------------------------//

void setup()
{

//--------------------------------------------------------------Début Initialisation Module 1-----------------------------------------------------------------------//
  pinMode(A0, INPUT);
  Serial.begin(9600);
//--------------------------------------------------------------Fin Initialisation Module 1-------------------------------------------------------------------------//
//--------------------------------------------------------------Début Initialisation Module 2-----------------------------------------------------------------------//

LED1 = 2;                                                             //Début d'initialisation des LEDS
LED2 = 3;
LED3 = 4;
LED4 = 5;
LED5 = 6;
LED6 = 7;
LED7 = 8;
LED8 = 9;
LED9 = 10;
LED10 = 11;                                                           //Fin d'initialisation des LEDs


for(compteur=LED1;compteur<=LED10;compteur++){                        //Initialisation des LEDs en tant que sortie
      pinMode(compteur,OUTPUT);
}

compteur = 1;                                                         //Initialisation du compteur servant pour les boucles
}

//--------------------------------------------------------------Fin Initialisation Module 2-------------------------------------------------------------------------//

void loop()
{
    //Serial.println(analogRead(0));                  //Permet de visualiser les battements de coeur et ajuster la sensibilité de mesure
//-----------------------------------------------------------------Début Code Module 1------------------------------------------------------------------------------//

  compteur1++;

  if(analogRead(0) >= 60){                          // quand on a une variation >=60
    battement = calculBattement(battement);         //on compte les battements
  }

  t = temps();                                      //fonction temps total

  if(compteur1 == 1000){                              //toutes les 1000 loop on affiche les valeurs
    pouls = calculPouls(battement);               
    Serial.print(t);                               //affiche temps
    Serial.print(";");                            
    Serial.print(pouls);                        //affiche pouls
    battement = 0;                               // renitialisation variables pour la prochaine boucle
    compteur1 = 0;
  }
  delay(1);                                    //attente entre chaque loop qui symbolise le temps

//------------------------------------------------------------------Fin Code Module 1-------------------------------------------------------------------------------//
//-----------------------------------------------------------------Début Code Module 2------------------------------------------------------------------------------//
launchLedHeart();           //Lancement de la fonction faisant fonctionner le coeur
//------------------------------------------------------------------Fin Code Module 2-------------------------------------------------------------------------------//

}
