//
// Created by Kader
//

#ifndef PROJETQUALITEPROG_MONSTREAVEUGLE_H
#define PROJETQUALITEPROG_MONSTREAVEUGLE_H

#include "monstre.h"

class monstreAveugle : public monstre {
public:
    monstreAveugle(int ptsVie, int ptsForce, int habilete, int x, int y);
    void seDeplace() override;



private:

};


#endif //PROJETQUALITEPROG_MONSTREAVEUGLE_H
