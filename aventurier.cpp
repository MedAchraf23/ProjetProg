#include "aventurier.h"
#include "config.h"



aventurier::aventurier(double vie, double force, const epee& epee, const armure& armure,const string& forme,Objet& config) :
    d_pointsVie{vie}, d_pointsForce{force}, d_epee{force}, d_armure{armure},
    d_forme(forme),d_possedeamulete{false},d_x{config.trouverCoordonneesaventurier().second}, d_y{config.trouverCoordonneesaventurier().second}{}


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



void aventurier::subirDegat(double f)
{
    d_pointsVie -= d_armure.attaqueMonstre(f);
}

double aventurier::attaque()
{   srand(time(0));
    d_epee.attaqueEpee();
    if(rand()%100<80)
    {return (d_pointsForce+d_epee.getPointSolidite())*0.9;
    }else return 0.0;
}

bool aventurier::possedeAmulette() const
{
    
    return d_possedeamulete;
}

void aventurier::setpossedeAmulette() 
{
   d_possedeamulete=true;

}

string aventurier::getForme()const
{
    return d_forme;
}

void aventurier::setforme(const string&  forme)
{
   d_forme=forme;
}


bool aventurier::estVivant() const
{
   return d_pointsVie!=0;

}