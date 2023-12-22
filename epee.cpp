#include"epee.h"

epee::epee(double pointSolidite):
    equipement{pointSolidite} {}

void epee::attaqueEpee()
{
    d_pointSolidite--;
    //*
}

/*
Quand un aventurier
attaque un monstre, le monstre reçoit une attaque d’un nombre de points de force égal aux points de
force de l’aventurier plus les points de solidité de l’épée (épée qui perd alors un point de solidité) et
multiplié par 0,9 avec une probabilité de 80 %.
*/
