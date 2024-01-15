//
// Created by Kader
//

#ifndef PROJETQUALITEPROG_MONSTREVOYANT_H
#define PROJETQUALITEPROG_MONSTREVOYANT_H

#include "monstre.h"

class Objet;

class monstreVoyant : public monstre {
public:
    monstreVoyant(double ptsVie, double ptsForce ,int posx,int posy, int habilete,const string& forme,Objet& config);
    void seDeplace(int aventurierX, int aventurierY)override;
    void seDeplace()override;


};

#endif //PROJETQUALITEPROG_MONSTREVOYANT_H
