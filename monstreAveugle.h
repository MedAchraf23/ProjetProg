//
// Created by Kader
//

#ifndef PROJETQUALITEPROG_MONSTREAVEUGLE_H
#define PROJETQUALITEPROG_MONSTREAVEUGLE_H

#include "monstre.h"
#include "include.h"

class Objet;
class monstreAveugle : public monstre {
public:
    monstreAveugle(int ptsVie, int ptsForce, int habilete,const string& forme,Objet& config);
    void seDeplace();

private:

};


#endif //PROJETQUALITEPROG_MONSTREAVEUGLE_H
