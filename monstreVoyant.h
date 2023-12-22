//
// Created by Kader
//

#ifndef PROJETQUALITEPROG_MONSTREVOYANT_H
#define PROJETQUALITEPROG_MONSTREVOYANT_H

#include "monstre.h"
#include "aventurier.h"

class monstreVoyant : public monstre {
public:
    monstreVoyant(int ptsVie, int ptsForce, int habilete, int x, int y);
    void seDeplace(int aventurierX, int aventurierY);

private:

};


#endif //PROJETQUALITEPROG_MONSTREVOYANT_H
