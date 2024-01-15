//
// Created by Kader
//

#include "monstreAveugle.h"

void monstreAveugle::seDeplace(int aventurierX, int aventurierY) {}

void monstreAveugle::seDeplace() {
    std::srand(std::time(0));
    int choix = std::rand() % 8 + 1;

    switch (choix) {
        case 1:
            deplaceBas();
            break;
        case 2:
            deplaceHaut();
            break;
        case 3:
            deplaceGauche();
            break;
        case 4:
            deplaceDroite();
            break;
        case 5:
            deplaceBasGauche();
            break;
        case 6:
            deplaceBasDroite();
            break;
        case 7:
            deplaceHautGauche();
        case 8:
            deplaceHautDroite();
            break;

    }
}




monstreAveugle::monstreAveugle(double ptsVie, double ptsForce,int posx,int posy, int habilete, const string& forme,Objet& config) : monstre{ptsVie,ptsForce,posx,posy,habilete,forme,config} {}
