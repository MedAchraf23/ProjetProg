#ifndef AVENTURIER_H_INCLUDED
#define AVENTURIER_H_INCLUDED

#include "equipement.h"
#include "epee.h"
#include "armure.h"

class aventurier
{
public:
    aventurier(double vie, double force, const epee& epee, const armure& armure, int xInit, int yInit);
    aventurier(double vie);
    aventurier(double vie, double force, int x, int y);
    double getVie() const;
    double getForce() const;
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    equipement getEpee() const;
    equipement getArmure() const;
    void deplacer(int choix);
    void subirDegat(double f);
    void attaque(double f);
private:
    double d_pointsVie;
    double d_pointsForce;
    int d_x, d_y;
    epee d_epee;
    armure d_armure;
    //boursePieces d_boursePieces;
};

#endif // AVENTURIER_H_INCLUDED
