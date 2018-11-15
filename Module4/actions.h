#ifndef MODULE4_ACTIONS_H
#define MODULE4_ACTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TEMPS 1000                      //utilisation pour moyenne()

#include "donnees.h"

void donneesBrut( int nb_line,struct Donnees *tab);

void ordreCroissantTemps(int nb_line, struct Donnees *tab);

void ordreCroissantPouls(int nb_line, struct Donnees *tab);

void ordreDecroissantTemps(int nb_line, struct Donnees *tab);

void ordreDecroissantPouls(int nb_line, struct Donnees *tab);

void rechercheFrequence(int nb_line, struct Donnees *tab, int frequence);

void moyenne(int nb_line, struct Donnees *tab,int borne1, int borne2);

void max(int nb_line, struct Donnees *tab);

void mini(int nb_line, struct Donnees *tab);

#endif //MODULE4_ACTIONS_H
