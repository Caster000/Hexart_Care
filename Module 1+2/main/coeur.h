#ifndef COEUR_H_INCLUDED
#define COEUR_H_INCLUDED

extern int LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8, LED9, LED10, compteur; 

void FullOn();
void FullOff();
void On1SurNb();
void Off1SurNb();
void chenille(int *compteur);
void chenille1sur2(int *compteur);
void LEDmetre(int *compteur);
void choixLED();
void launchLedHeart();

#endif //COEUR_H_INCLUDED
