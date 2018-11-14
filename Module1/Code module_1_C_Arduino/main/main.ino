#include "cardio.c"
#include "cardio.h"
long t;
int compteur = 0;
int battement = 0;
int pouls = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  compteur++;

  if(analogRead(0) >= 60){
    battement = calculBattement(battement);
  }

  t = temps();

  if(compteur == 150){ 
    pouls = calculPouls(battement);
    Serial.print(t);
    Serial.print(";");
    Serial.println(pouls);
    battement = 0;
    compteur = 0;
  }
  delay(10);
}
