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
    int choix;
    do
    {
        std::cout<<"MENU PRINCIPAL :"<<'\n'<<'\n';
        std::cout<<"(1) Lancer la partie"<<'\n';
        std::cout<<"(2) Creer/editer le terrain d’un cheteau"<<'\n';
        std::cout<<"(3) Charger la configuration d’un terrain"<<'\n';
        std::cout<<std::endl<<"Votre choix : ";
        std::cin>>choix;
    }
    while (choix<1 || choix>3);
    return choix;
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
