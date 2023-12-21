#ifndef AVENTURIER_H_INCLUDED
#define AVENTURIER_H_INCLUDED

#include "equipement.h"

class aventurier
{
public:
    aventurier(int vie, int force, const epee& epee, const armure& armure, int xInit, int yInit);
    aventurier(int vie);
    int getVie() const;
    int getForce() const;
    int getX() const;
    int getY() const;
    void setX();
    void setY();
    equipement getEpee() const;
    equipement getArmure() const;
    void deplacer(int choix);
    //void resterSurPlace();
    void subirDegat(int f);
    void attaque(int f);
private:
    int d_pointsVie;
    int d_pointsForce;
    int d_x, d_y;
    equipement d_epee;
    equipement d_armure;
    //boursePieces d_boursePieces;
};

#endif // AVENTURIER_H_INCLUDED
