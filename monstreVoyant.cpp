//
// Created by Kader
//

#include "monstreVoyant.h"

monstreVoyant::monstreVoyant(double ptsVie, double ptsForce,int posx,int posy, int habilete,const string& forme,Objet& config):monstre{ptsVie,ptsForce,posx,posy,habilete,forme,config}
{}


void monstreVoyant::seDeplace()
{}

void monstreVoyant::seDeplace(int aventurierX, int aventurierY) {
    int xposAventurier = aventurierX;
    int yposAventurier = aventurierY;

    int distanceX = xposAventurier - x();
    int distanceY = yposAventurier - y();

    if (std::abs(distanceX) <= 8 && std::abs(distanceY) <= 8) {
        
        if (xposAventurier == x()) {
            if (distanceY < 0) {
                deplaceHaut();
            } else if (distanceY > 0) {
                deplaceBas();
            }
        }
      
        else if (yposAventurier == y()) {
            if (distanceX < 0) {
                deplaceGauche();
            } else if (distanceX > 0) {
                deplaceDroite();
            }
        }

        else {
            if (distanceX < 0) {
                deplaceGauche();
            } else {
                deplaceDroite();
            }
        }
    }
}
