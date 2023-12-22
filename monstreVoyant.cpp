//
// Created by Kader
//

#include "monstreVoyant.h"

monstreVoyant::monstreVoyant(int ptsVie, int ptsForce, int habilete, int x, int y):monstre{ptsVie,ptsForce,habilete,x,y}
{}

void monstreVoyant::seDeplace(const aventurier &a) {
    int xposAventurier = a.getX();
    int yposAventurier = a.getY();

    int distanceX = xposAventurier - x();
    int distanceY = yposAventurier - y();

        if(distanceX>=-8&&distanceX<=8 && distanceY>=-8&&distanceY<=8 && xposAventurier!=x())
        {
            if(distanceX<0)
            {
                deplaceGauche();
            }

            else { deplaceDroite();};

        }

        else if(distanceX>=-8&&distanceX<=8 && distanceY>=-8&&distanceY<=8 && xposAventurier==x())
        {
            if(yposAventurier<y())
            {
                deplaceHaut();
            }
            else
            {
                deplaceBas();
            }
        }

        else
        {
            //deplace random
        }
}
