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
    monstre(int ptsVie, int ptsForce, int habilete,const string& forme,Objet& config);
    virtual void seDeplace(int aventurierX, int aventurierY) = 0;
    //void attaque(const aventurier& a);
    void perdPointsVie(int force);
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

private:
    int d_pointsVie;
    int d_pointsForce;
    int d_habilete;
    int d_x, d_y;
    bool d_vivant;
    string d_forme;
};

//test
//test2


#endif //PROJET_QUALITÉ_PROG_MONSTRE_H
