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
attaque un monstre, le monstre re�oit une attaque d�un nombre de points de force �gal aux points de
force de l�aventurier plus les points de solidit� de l��p�e (�p�e qui perd alors un point de solidit�) et
multipli� par 0,9 avec une probabilit� de 80 %.
*/
