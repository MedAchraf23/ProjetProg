//
// Created by Kader on 20/12/2023.
//

#ifndef PROJET_QUALITÉ_PROG_MONSTRE_H
#define PROJET_QUALITÉ_PROG_MONSTRE_H

#include <random>
#include <ctime>

class monstre {
public:
    virtual ~monstre() = default;
    monstre(int ptsVie, int ptsForce, int habilete, int x, int y);
    virtual void seDeplace() = 0;
    //void attaque(const aventurier& a);
    void perdPointsVie(int force);
    int attaque() const;


    bool estVivant() const;
    int pointsVie() const;
    int habilete() const;
    int pointsForce() const;
    int x() const;
    int y() const;


private:
    int d_pointsVie;
    int d_pointsForce;
    int d_habilete;
    int d_x, d_y;
    bool d_vivant;
};


#endif //PROJET_QUALITÉ_PROG_MONSTRE_H
