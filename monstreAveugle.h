//
// Created by Kader
//

#ifndef PROJETQUALITEPROG_MONSTREAVEUGLE_H
#define PROJETQUALITEPROG_MONSTREAVEUGLE_H

#include "aventurier.h"
#include "monstre.h"
#include "ctime"
#include "random"

class monstreAveugle : public monstre {
public:
    monstreAveugle(int ptsVie, int ptsForce, int habilete, int x, int y);
    void seDeplace();

private:

};


#endif //PROJETQUALITEPROG_MONSTREAVEUGLE_H
