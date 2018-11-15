#include <stdio.h>
#include <stdlib.h>

int main()
{

    if(startMenu()==0){                                 //Démarre le menu et teste s'il s'est bien terminé
        system("pause");
        system("CLS");
        printf("Tout s'est bien termine. Votre coeur de LED est pret pour utilisation.\n");
    }else{
        printf("Erreur durant l'execution du programme. Il est possible que vos donnees n'aient pas ete enregistrees.\n");
    }

    return 0;
}
