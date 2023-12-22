#include "affichage.h"

affichage::affichage(const ostream& ost, const aventurier& aventurier, const terrain& terrain, const monstre& monstre) :
    d_ost{ost}, d_aventurier{aventurier}, d_terrain{terrain}, d_monstre{monstre}
{

}

aventurier affichage::getAventurier() const
{
    return d_aventurier;
}

terrain affichage::getTerrain() const
{
    return d_terrain;
}

monstre affichage::getMonstre() const
{
    return d_monstre;
}

void affichage::afficheMenu() const
{

}

void affichage::afficheTerrain() const
{

}

void affichage::afficheAventurier() const
{

}

void affichage::afficheMonstre() const
{

}

void affichage::afficheConfigAventurier() const
{

}

void affichage::afficheDesTouchesDeplacement() const
{

}
