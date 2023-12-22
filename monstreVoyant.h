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
<<<<<<< HEAD
    void seDeplace(int aventurierX, int aventurierY);
=======
    void seDeplace(const aventurier& a);

private:

>>>>>>> 2d9958d1e85f0f5234a855d2f2e0a5bfd5048f99
};


#endif //PROJETQUALITEPROG_MONSTREVOYANT_H
