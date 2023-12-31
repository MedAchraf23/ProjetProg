//
// Created by Kader
//

#include "monstre.h"


int monstre::habilete() const
{ return d_habilete; }

int monstre::pointsVie() const
{ return d_pointsVie; }

int monstre::pointsForce() const
{ return d_pointsForce; }

bool monstre::estVivant() const
{ if (d_pointsVie<=0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int monstre::x() const
{
    return d_x;
}

int monstre::y() const
{
    return d_y;
}

int monstre::attaque() const
{
    srand(time(NULL));
    int a = rand() % (100 - 0 + 1) + 0;
    if(a<=d_habilete)
        {
        return d_pointsForce * 0, 9;
        }
    else
        {
        return 0;
        }
}

void monstre::perdPointsVie(int force)
{
    d_pointsVie-force;
    d_vivant = estVivant();
}

monstre::monstre(int ptsVie, int ptsForce, int habilete, int x, int y) : d_pointsVie{ptsVie},
d_pointsForce{ptsForce}, d_habilete{habilete}, d_x{x}, d_y{y},d_vivant{true}
{

}

void monstre::deplaceHaut()
{
    d_y--;
}

void monstre::setX(int x)
{
    d_x = x;
}

void monstre::setY(int y)
{
    d_y = y;
}

void monstre::deplaceBas()
{
    d_y++;
}


void monstre::deplaceGauche()
{
    d_x--;
}

void monstre::deplaceDroite()
{
    d_x++;
}

void monstre::deplaceBasDroite()
{
    d_y++;
    d_x++;
}

void monstre::deplaceHautGauche()
{
    d_y--;
    d_x--;
}

void monstre::deplaceHautDroite()
{
    d_y--;
    d_x++;
}

void monstre::deplaceBasGauche()
{
    d_x--;
    d_y++;
}

