//
// Created by Kader
//

#include "monstreAveugle.h"


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

monstreAveugle::monstreAveugle(int ptsVie, int ptsForce, int habilete, int x, int y) : monstre{ptsVie,ptsForce,habilete,x,y}
{}
