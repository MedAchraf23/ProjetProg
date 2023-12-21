#include "aventurier.h"

aventurier::aventurier(int vie, int force, const epee& epee, const armure& armure, int xInit, int yInit) :
    d_pointsVie{vie}, d_pointsForce{force}, d_epee{epee}, d_armure{armure}, d_x{xInit}, d_y{yInit}
{

}

aventurier::aventurier(int vie) :
    d_pointsVie{vie}, d_pointsForce{0}, d_x{0}, d_y{0}
{

}

aventurier::aventurier(int vie, int force, int x, int y) :
    d_pointsVie{vie}, d_pointsForce{force}, d_x{x}, d_y{y}
{

}

int aventurier::getVie() const
{
    return d_pointsVie;
}

int aventurier::getForce() const
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


void aventurier::subirDegat(int f)
{
    //d_pointsVie -= d_armure.attaquemonstre(f);
}

void aventurier::attaque(int f)
{
    //d_epee.attaqueepee();
}
