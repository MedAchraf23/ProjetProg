#ifndef AVENTURIER_H_INCLUDED
#define AVENTURIER_H_INCLUDED

#include "equipement.h"
#include "epee.h"
#include "armure.h"
#include "amulette.h"
#include "include.h"


class Objet;


class aventurier
{
public:
    
    aventurier(double vie, double force, const epee& epee, const armure& armure,const string& forme,Objet& config);
    double getVie() const;
    double getForce() const;
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    epee getEpee() const;
    armure getArmure() const;
    void subirDegat(double f);
    double attaque();
    bool possedeAmulette() const;
    void setpossedeAmulette();
    string getForme()const;
    void setforme(const string& forme);
    bool estVivant() const;
private:
    double d_pointsVie;
    double d_pointsForce;
    int d_x, d_y;
    epee d_epee;
    armure d_armure;
    string d_forme;
    bool d_possedeamulete;
    
 
};

#endif // AVENTURIER_H_INCLUDED
