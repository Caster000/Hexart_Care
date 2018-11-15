#include "param.h"
#include "coeur.h"
#include <arduino.h>

void launchLedHeart() {
  if (analogRead(0) >= SENSIBILITE) {                       /* SENSIBILITE CONSEILLEE >950 afin de supprimer les interférences de la carte
                                                               et obtenir une meilleure temporisation (elle démarre à 480 lors du lancement)*/

    switch (MODE) {                                         //Selection du mode d'affichage défini dans param.h

      case 1 :                                              /*Cas allumage en flash de toutes les LEDs, configurer une SENSIBILITE à une valeur supérieure à 950
                                                              pour pouvoir afficher les battements d'un coeur plus rapide*/
        FullOn();                                           //Allumage complet
        delay(1);                                           //Delay afin de pouvoir laisser les LEDs s'allumer
        FullOff();                                          //Extinction complète
        break;                                              //-----------------------------------------------------------------------------------------------------------

      case 2 :                                              //Cas d'allumage des LEDs en mode chenille
        if (analogRead(0) >= SENSIBILITE + 25) {
          chenille(&compteur);
          delay(1000);
          compteur++;
        }
        break;                                              //-----------------------------------------------------------------------------------------------------------

      case 3 :                                              //Cas d'allumage des LEDs en mode chenille, allumage d'une LED sur deux
        if (analogRead(0) >= SENSIBILITE + 25) {
          chenille1sur2(&compteur);
          delay(1000);                                      //Attente afin de faire redescendre la valeur du PIN d'entrée
          compteur++;                                       //Incrémentation du compteur servant à passer à l'étape d'après pour le prochain appel de la fonction
        }
        break;                                              //-----------------------------------------------------------------------------------------------------------

      case 4 :                                              //Cas d'affichage en LEDmètre (affichage en mode pile informatique)
        if (analogRead(0) >= SENSIBILITE + 25) {
          LEDmetre(&compteur);
          delay(1000);                                      //Attente afin de faire redescendre la valeur du PIN d'entrée
          compteur++;                                       //Incrémentation du compteur servant à passer à l'étape d'après pour le prochain appel de la fonction
        }
        break;                                              //-----------------------------------------------------------------------------------------------------------

      case 5 :                                              //Cas d'allumage d'une seule LED, au choix

        choixLED();
        break;                                              //-----------------------------------------------------------------------------------------------------------

      case 6 :                                              //Cas d'allumage d'une LED en sautant un nombre déterminé d'autres LEDs

        On1SurNb();                                         //Allumage de 1 LED sur un nombre déterminé
        delay(1);                                          //Attente afin de laisser les LEDs s'allumer et la tension dans le PIN redescendre
        Off1SurNb();                                        //Extinction de 1 LED sur un nombre déterminé
        break;

      default :
        break;
    }                                                                 //Fin du switch

  }                                                                   //Fin du if de vérification d'un poul
}

void FullOn() {                                                       //Fonction allumant toutes les LEDs
  int j;
  for (j = LED1; j <= LED10; j++) {
    digitalWrite(j, HIGH);
  }
}

void FullOff() {                                                      //Fonction éteignant toutes les LEDs
  int j;
  for (j = LED1; j <= LED10; j++) {
    digitalWrite(j, LOW);
  }
}

void On1SurNb() {                                                     //Fonction allumant 1 LED sur UNSURNB (définie dans param.h)
  int j;
  for (j = LED1; j <= LED10; j += UNSURNB) {
    digitalWrite(j, HIGH);
  }
}

void Off1SurNb() {                                                    //Fonction éteignant 1 LED sur UNSURNB (définie dans param.h)
  int j;
  for (j = LED1; j <= LED10; j += UNSURNB) {
    digitalWrite(j, LOW);
  }
}

void chenille(int *compteur) {                                        //Fonction faisant une chenille d'allumage de LEDs

  switch (*compteur) {

    case 1 :
      digitalWrite(LED1, HIGH);                                         //Allumage LED1
      break;

    case 2 :
      digitalWrite(LED2, HIGH);                                         //Allumage LED2
      break;

    case 3 :
      digitalWrite(LED3, HIGH);                                         //Allumage LED3
      break;

    case 4 :
      digitalWrite(LED4, HIGH);                                         //Allumage LED4
      break;

    case 5 :
      digitalWrite(LED5, HIGH);                                         //Allumage LED5
      break;

    case 6 :
      digitalWrite(LED6, HIGH);                                         //Allumage LED6
      break;

    case 7 :
      digitalWrite(LED7, HIGH);                                         //Allumage LED7
      break;

    case 8 :
      digitalWrite(LED8, HIGH);                                         //Allumage LED8
      break;

    case 9 :
      digitalWrite(LED9, HIGH);                                         //Allumage LED9
      break;

    case 10 :
      digitalWrite(LED10, HIGH);                                        //Allumage LED10
      break;

    case 11 :
      digitalWrite(LED1, LOW);                                          //Extinction LED1
      break;

    case 12 :
      digitalWrite(LED2, LOW);                                          //Extinction LED2
      break;

    case 13 :
      digitalWrite(LED3, LOW);                                          //Extinction LED3
      break;

    case 14 :
      digitalWrite(LED4, LOW);                                          //Extinction LED4
      break;

    case 15 :
      digitalWrite(LED5, LOW);                                          //Extinction LED5
      break;

    case 16 :
      digitalWrite(LED6, LOW);                                          //Extinction LED6
      break;

    case 17 :
      digitalWrite(LED7, LOW);                                          //Extinction LED7
      break;

    case 18 :
      digitalWrite(LED8, LOW);                                          //Extinction LED8
      break;

    case 19 :
      digitalWrite(LED9, LOW);                                          //Extinction LED9
      break;

    case 20 :
      digitalWrite(LED10, LOW);                                         //Extinction LED10
      *compteur = 0;
      break;

    default :
      break;
  }
}                                                                       //Fin de la fonction chenille

void chenille1sur2(int *compteur) {                                     //Fonction faisant une chenille de LEDs en allumant 1 LED/2

  switch (*compteur) {

    case 1 :                                                              //Début de l'allumage des LEDs
      digitalWrite(LED1, HIGH);                                         //Allumage LED1
      break;

    case 2 :
      digitalWrite(LED3, HIGH);                                         //Allumage LED3
      break;

    case 3 :
      digitalWrite(LED5, HIGH);                                         //Allumage LED5
      break;

    case 4 :
      digitalWrite(LED7, HIGH);                                         //Allumage LED7
      break;

    case 5 :
      digitalWrite(LED9, HIGH);                                         //Allumage LED9
      break;

    case 6 :
      digitalWrite(LED2, HIGH);                                         //Allumage LED2
      break;

    case 7 :
      digitalWrite(LED4, HIGH);                                         //Allumage LED4
      break;

    case 8 :
      digitalWrite(LED6, HIGH);                                         //Allumage LED6
      break;

    case 9 :
      digitalWrite(LED8, HIGH);                                         //Allumage LED8
      break;

    case 10 :
      digitalWrite(LED10, HIGH);                                        //Alumage LED10
      break;                                                            //Fin d'allumage des LEDs

    case 11 :                                                          //Début de l'extinction des LEDs
      digitalWrite(LED1, LOW);                                          //Extinction LED1
      break;

    case 12 :
      digitalWrite(LED3, LOW);                                          //Extinction LED3
      break;

    case 13 :
      digitalWrite(LED5, LOW);                                          //Extinction LED5
      break;

    case 14 :
      digitalWrite(LED7, LOW);                                          //Extinction LED7
      break;

    case 15 :
      digitalWrite(LED9, LOW);                                          //Extinction LED9
      break;

    case 16 :
      digitalWrite(LED2, LOW);                                          //Extinction LED2
      break;

    case 17 :
      digitalWrite(LED4, LOW);                                          //Extinction LED4
      break;

    case 18 :
      digitalWrite(LED6, LOW);                                          //Extinction LED6
      break;

    case 19 :
      digitalWrite(LED8, LOW);                                          //Extinction LED8
      break;

    case 20 :
      digitalWrite(LED10, LOW);                                          //Extinction LED10
      *compteur = 0;                                                     //Remise à zéro du compteur allumant les LEDs
      break;                                                             //Fin d'extinction des LEDs

    default :
      break;
  }
}                                                                      //Fin fonction chenille de LED 1/2

void LEDmetre(int *compteur) {                                         //Fonction allumant les LEDs sur un modèle de pile informatique

  switch (*compteur) {

    case 1 :                                                             //Début de l'allumage des LEDs
      digitalWrite(LED1, HIGH);                                           //Allumage LED1
      break;

    case 2 :
      digitalWrite(LED2, HIGH);                                           //Allumage LED2
      break;

    case 3 :
      digitalWrite(LED3, HIGH);                                           //Allumage LED3
      break;

    case 4 :
      digitalWrite(LED4, HIGH);                                           //Allumage LED4
      break;

    case 5 :
      digitalWrite(LED5, HIGH);                                           //Allumage LED5
      break;

    case 6 :
      digitalWrite(LED6, HIGH);                                           //Allumage LED6
      break;

    case 7 :
      digitalWrite(LED7, HIGH);                                           //Allumage LED7
      break;

    case 8 :
      digitalWrite(LED8, HIGH);                                           //Allumage LED8
      break;

    case 9 :
      digitalWrite(LED9, HIGH);                                           //Allumage LED9
      break;

    case 10 :
      digitalWrite(LED10, HIGH);                                          //LED10
      break;                                                            //Fin d'allumage des LEDs

    case 11 :                                                          //Début de l'extinction des LEDs
      digitalWrite(LED10, LOW);                                         //Extinction LED10
      break;

    case 12 :
      digitalWrite(LED9, LOW);                                          //Extinction LED9
      break;

    case 13 :
      digitalWrite(LED8, LOW);                                          //Extinction LED8
      break;

    case 14 :
      digitalWrite(LED7, LOW);                                          //Extinction LED7
      break;

    case 15 :
      digitalWrite(LED6, LOW);                                          //Extinction LED6
      break;

    case 16 :
      digitalWrite(LED5, LOW);                                          //Extinction LED5
      break;

    case 17 :
      digitalWrite(LED4, LOW);                                          //Extinction LED4
      break;

    case 18 :
      digitalWrite(LED3, LOW);                                          //Extinction LED3
      break;

    case 19 :
      digitalWrite(LED2, LOW);                                          //Extinction LED2
      break;

    case 20 :
      digitalWrite(LED1, LOW);                                          //Extinction LED1
      *compteur = 0;                                                    //Remise à zéro du compteur allumant les LEDs
      break;                                                            //Fin extinction des LEDs

    case 21:

      break;

    default :
      break;
  }
}                                                                      //Fin fonction LEDmètre

void choixLED() {                                                      //Fonction permettant de choisir une LED à allumer

  switch (LED) {

    case 1 :                                                             //Allumage LED1
      digitalWrite(LED1, HIGH);
      delay(1);
      digitalWrite(LED1, LOW);                                           //Extinction LED1
      break;

    case 2 :
      digitalWrite(LED2, HIGH);
      delay(1);                                                          //LED2
      digitalWrite(LED2, LOW);
      break;

    case 3 :
      digitalWrite(LED3, HIGH);
      delay(1);                                                          //LED3
      digitalWrite(LED3, LOW);
      break;

    case 4 :
      digitalWrite(LED4, HIGH);
      delay(1);                                                          //LED4
      digitalWrite(LED4, LOW);
      break;

    case 5 :
      digitalWrite(LED5, HIGH);
      delay(1);                                                          //LED5
      digitalWrite(LED5, LOW);
      break;

    case 6 :
      digitalWrite(LED6, HIGH);
      delay(1);                                                          //LED6
      digitalWrite(LED6, LOW);
      break;

    case 7 :
      digitalWrite(LED7, HIGH);
      delay(1);                                                          //LED7
      digitalWrite(LED7, LOW);
      break;

    case 8 :
      digitalWrite(LED8, HIGH);
      delay(1);                                                          //LED8
      digitalWrite(LED8, LOW);
      break;

    case 9 :
      digitalWrite(LED9, HIGH);
      delay(1);                                                          //LED9
      digitalWrite(LED9, LOW);
      break;

    case 10 :
      digitalWrite(LED10, HIGH);
      delay(1);                                                          //LED10
      digitalWrite(LED10, LOW);
      break;

    default :
      FullOn();
      delay(1);                                                          //Clignotement x1 de toutes les LEDs montrant une erreur
      FullOff();
      break;
  }
}                                                                       //Fin fonction choix de la LED
