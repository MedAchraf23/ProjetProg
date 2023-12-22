#include "affichage.h"



affichage::affichage(const ostream& ost, const aventurier& aventurier, const monstreAveugle& monstreAveugle, const monstreVoyant& monstreVoyant, const terrain& terrain, const monstre& monstre) :
    d_ost{ost}, d_aventurier{aventurier}, d_monstreAveugle{monstreAveugle}, d_monstreVoyant{monstreVoyant}, d_terrain{terrain}, d_monstre{monstre}
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

monstreAveugle affichage::getMonstreAveugle() const
{
    return d_monstreAveugle;
}

monstreVoyant affichage::getMonstreVoyant() const
{
    return d_monstreVoyant;
}


int affichage::choixMenu() const
{
    int choix;
    do
    {
        std::cout<<"MENU PRINCIPAL :"<<'\n'<<'\n';
        std::cout<<"(1) Lancer la partie"<<'\n';
        std::cout<<"(2) Creer/editer le terrain d�un cheteau"<<'\n';
        std::cout<<"(3) Charger la configuration d�un terrain"<<'\n';
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

void affichage::afficheMonstreVoyant() const
{

}

void affichage::afficheMonstreAveugle() const
{

}

void affichage::afficheInfoAventurier() const
{
    std::cout<<"Points de vie : "<<d_aventurier.getVie()<<'/n';
    std::cout<<"Points de force : "<<d_aventurier.getForce()<<'/n';
    std::cout<<"Solidite armure : "<<d_aventurier.getArmure().getPointSolidite()<<'/n';
    std::cout<<"Solidite epee : "<<d_aventurier.getArmure().getPointSolidite()<<'/n';
}
