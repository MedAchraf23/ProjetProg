#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include <fstream>
#include "aventurier.h"
#include "terrain.h"
#include "monstre.h"
#include "amulette.h"

using std::cout;
using std::cin;
using std::endl;

class affichage
{
public:
    //affichage();
    void afficheMenu(int choix) const;
    void afficheTerrain(std::ofstream& fichier) const;
    void afficheAventurier() const;
    void afficheMonstre() const;
    void afficheInfoAventurier(const aventurier& a) const;
    void afficheDesTouchesDeplacement() const;
    void afficheAmulette() const;
private:
    //std::ofstream d_ost;
};


#endif // AFFICHAGE_H_INCLUDED
