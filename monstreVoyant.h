//
// Created by Kader on 20/12/2023.
//

#ifndef PROJETQUALITEPROG_MONSTREVOYANT_H
#define PROJETQUALITEPROG_MONSTREVOYANT_H

#include "monstre.h"

class monstreVoyant : public monstre {
public:
    monstreVoyant(int ptsVie, int ptsForce, int habilete, int x, int y);
    void seDeplace() override;

};


#endif //PROJETQUALITEPROG_MONSTREVOYANT_H
