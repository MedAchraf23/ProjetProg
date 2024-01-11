//
// Created by Kader
//

#ifndef PROJETQUALITEPROG_MONSTREVOYANT_H
#define PROJETQUALITEPROG_MONSTREVOYANT_H

#include "monstre.h"

class Objet;

class monstreVoyant : public monstre {
public:
    monstreVoyant(int ptsVie, int ptsForce, int habilete,const string& forme,Objet& config);
    void seDeplace(int aventurierX, int aventurierY)override;

private:

};

#endif //PROJETQUALITEPROG_MONSTREVOYANT_H
