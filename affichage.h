<<<<<<< HEAD
//#ifndef AFFICHAGE_H_INCLUDED
//#define AFFICHAGE_H_INCLUDED
//
//#include <iostream>
//#include "aventurier.h"
//#include "terrain.h"
//#include "monstre.h"
//#include "amulette.h"
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//class affichage
//{
//public:
//    affichage(const std::ostream& ost, const aventurier& aventurier, const terrain& terrain, const monstre& monstre, const amulette& amulette);
//    aventurier getAventurier() const;
//    terrain getTerrain() const;
//    monstre getMonstre() const;
//    void afficheMenu() const;
//    void afficheTerrain() const;
//    void afficheAventurier() const;
//    void afficheMonstre() const;
//    void afficheInfoAventurier() const;
//    void afficheDesTouchesDeplacement() const;
//    void afficheAmulette() const;
//private:
//    ostream d_ost;
//    aventurier d_aventurier;
//    terrain d_terrain;
//    monstre d_monstre;
//    amulette d_amulette;
//};
//
//
//#endif // AFFICHAGE_H_INCLUDED
=======
#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include <iostream>
#include "aventurier.h"
#include "terrain.h"
#include "monstreAveugle.h"
#include "monstreVoyant.h"
#include "amulette.h"

using std::cout;
using std::cin;
using std::endl;

class affichage
{
public:
    affichage(const std::ostream& ost, const aventurier& aventurier, const terrain& terrain, const monstreAveugle& monstreAveugle, const monstreVoyant& monstrVoyant, const amulette& amulette);
    aventurier getAventurier() const;
    terrain getTerrain() const;
    monstreAveugle getMonstreAveugle() const;
    monstreVoyant getMonstreVoyant() const;
    int choixMenu() const;
    void afficheTerrain() const;
    void afficheAventurier() const;
    void afficheMonstreVoyant() const;
    void afficheMonstreAveugle() const;
    void afficheInfoAventurier() const;
    void afficheDesTouchesDeplacement() const;
    void afficheAmulette() const;
private:
    ostream d_ost;
    aventurier d_aventurier;
    terrain d_terrain;
    monstreAveugle d_monstreAveugle;
    monstreVoyant d_monstreVoyant;
    amulette d_amulette;
};


#endif // AFFICHAGE_H_INCLUDED
>>>>>>> 2d9958d1e85f0f5234a855d2f2e0a5bfd5048f99
