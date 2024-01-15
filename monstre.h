//
// Created by Kader
//

#ifndef PROJET_QUALITÉ_PROG_MONSTRE_H
#define PROJET_QUALITÉ_PROG_MONSTRE_H

#include "include.h"


class Objet;

class monstre {
public:
    virtual ~monstre() = default;
    monstre(double ptsVie, double ptsForce,int posx,int posy, int habilete,const string& forme,Objet& config);
    virtual void seDeplace(int aventurierX, int aventurierY) = 0;
    virtual void seDeplace() =0;
    
    void perdPointsVie(double force);
    int attaque() const;

    void setX(int x);
    void setY(int y);

    void deplaceHaut();
    void deplaceBas();
    void deplaceGauche();
    void deplaceDroite();

    void deplaceHautDroite();
    void deplaceHautGauche();
    void deplaceBasDroite();
    void deplaceBasGauche();


    bool estVivant() const;
    int pointsVie() const;
    int habilete() const;
    int pointsForce() const;
    int x() const;
    int y() const;
    string getforme()const;

protected:
    double d_pointsVie;
    double d_pointsForce;
    int d_habilete;
    int d_x, d_y;
    bool d_vivant;
    string d_forme;
};

//test
//test2


#endif //PROJET_QUALITÉ_PROG_MONSTRE_H
