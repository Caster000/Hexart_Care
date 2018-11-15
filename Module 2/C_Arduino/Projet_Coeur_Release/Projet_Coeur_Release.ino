include "coeur.c"

void setup() {

}

void loop() {

  if (analogRead(0) >= SENSIBILITE) {             /* SENSIBILITE CONSEILLEE >950 afin de supprimer les interférences de la carte
                                                     et obtenir une meilleure temporisation (elle démarre à 480 lors du lancement)*/

    switch (MODE) {                               //Selection du mode d'affichage défini dans param.h

      case 1 :                                    /*Cas allumage en flash de toutes les LEDs, configurer une SENSIBILITE à une valeur supérieure à 950
                                                    pour pouvoir afficher les battements d'un coeur plus rapide*/
        FullOn();                                 //Allumage complet
        delay(1);                                 //Delay afin de pouvoir laisser les LEDs s'allumer
        FullOff();                                //Extinction complète
        break;                                    //-----------------------------------------------------------------------------------------------------------

      case 2 :                                    //Cas d'allumage des LEDs en mode chenille
        if (analogRead(0) >= SENSIBILITE + 25) {
          chenille(&compteur);
          delay(1000);
          compteur++;
        }
        break;                                   //-----------------------------------------------------------------------------------------------------------

      case 3 :                                    //Cas d'allumage des LEDs en mode chenille, allumage d'une LED sur deux
        if (analogRead(0) >= SENSIBILITE + 25) {
          chenille1sur2(&compteur);
          delay(1000);                            //Attente afin de faire redescendre la valeur du PIN d'entrée
          compteur++;                             //Incrémentation du compteur servant à passer à l'étape d'après pour le prochain appel de la fonction
        }
        break;                                    //-----------------------------------------------------------------------------------------------------------

      case 6 :                                    //Cas d'affichage en LEDmètre (affichage en mode pile informatique)
        if (analogRead(0) >= SENSIBILITE + 25) {
          LEDmetre(&compteur);
          delay(1000);                            //Attente afin de faire redescendre la valeur du PIN d'entrée
          compteur++;                             //Incrémentation du compteur servant à passer à l'étape d'après pour le prochain appel de la fonction
        }
        break;                                    //-----------------------------------------------------------------------------------------------------------

      case 7 :                                    //Cas d'allumage d'une seule LED, au choix

        choixLED();
        break;                                    //-----------------------------------------------------------------------------------------------------------

      case 8 :                                    //Cas d'allumage d'une LED en sautant un nombre déterminé d'autres LEDs

        On1SurNb();                               //Allumage de 1 LED sur un nombre déterminé
        delay(1);                                 //Attente afin de laisser les LEDs s'allumer
        Off1SurNb();                              //Extinction de 1 LED sur un nombre déterminé
        break;

      default :
        break;
    }                                             //Fin du switch

  }                                               //Fin du if de vérification d'un poul
}                                                 //Fin loop()
