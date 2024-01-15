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
    monstreAveugle(double ptsVie, double ptsForce,int posx,int posy, int habilete,const string& forme,Objet& config);
    void seDeplace()override;
    void seDeplace(int aventurierX, int aventurierY) override;


};


#endif //PROJETQUALITEPROG_MONSTREAVEUGLE_H
