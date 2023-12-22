#include "aventurier.h"


aventurier::aventurier(double vie, double force, const epee& epee, const armure& armure) :
    d_pointsVie{vie}, d_pointsForce{force}, d_epee{force}, d_armure{armure}, d_x{xInitial}, d_y{yInitial}
{

}

double aventurier::getVie() const
{
    return d_pointsVie;
}

double aventurier::getForce() const
{
    return d_pointsForce;
}

int aventurier::getX() const
{
    return d_x;
}

void aventurier::setX(int x)
{
    d_x = x;
}

void aventurier::setY(int y)
{
    d_y = y;
}

int aventurier::getY() const
{
    return d_y;
}

armure aventurier::getArmure() const
{
    return d_armure;
}

epee aventurier::getEpee() const
{
    return d_epee;
}

void aventurier::deplacer(int choix)
{
    bool m = true;
    while(m)
    {
        switch(choix)
        {
            case 1: //droite
                d_x++;
                break;
            case 2: //gauche
                d_x--;
                break;
            case 3: //haut
                d_y++;
                break;
            case 4: //bas
                d_y--;
                break;
            case 5: //diagonaleHautDroite
                d_x++;
                d_y++;
                break;
            case 6: //diagonaleHautGauche
                d_x--;
                d_y++;
                break;
            case 7: //diagonaleBasDroite
                d_x++;
                d_y--;
                break;
            case 8: //diagonaleBasGauche
                d_x--;
                d_y--;
                break;
            default:
                m = false;
        }
    }
}


void aventurier::subirDegat(double f)
{
    d_pointsVie -= d_armure.attaqueMonstre(f);
}

void aventurier::attaque(double f)
{
    d_epee.attaqueEpee();
}

bool aventurier::possedeAmulette(const amulette& a) const
{
    if(d_x == a.getX() && d_y == a.getY())
    {
        return true;
    }
    else
        return false;
}
