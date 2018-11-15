#include "cardio.c"
#include "cardio.h"
//#include "coeur.c"
//#include "coeur.h"

long t;                           //temps
int compteur1 = 0;                 //periodicité mesure
int battement = 0;
int pouls = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);           
}

void loop()
{
  compteur1++;

  if(analogRead(0) >= 60){                          // quand on a une variation >=60
    battement = calculBattement(battement);         //on compte les battements
  }

  t = temps();                                      //fonction temps total

  if(compteur == 1000){                              //toutes les 1000 loop on affiche les valeurs
    pouls = calculPouls(battement);               
    Serial.print(t);                               //affiche temps
    Serial.print(";");                            
    Serial.print(pouls);                        //affiche pouls
    battement = 0;                               // renitialisation variables pour la prochaine boucle
    compteur1 = 0;
  }
  delay(1);                                    //attente entre chaque loop qui symbolise le temps
}
