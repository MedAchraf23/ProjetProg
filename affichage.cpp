#include "affichage.h"

/*
affichage::affichage() :
{

}
*/

void affichage::afficheMenu(int choix) const
{
    do
    {
        cout<<"MENU PRINCIPAL :"<<'\n'<<'\n';
        cout<<"(1) Lancer la partie"<<'\n';
        cout<<"(2) Creer/editer le terrain d’un chateau"<<'\n';
        cout<<"(3) Charger la configuration d’un terrain"<<'\n';
        cout<<std::endl<<"Votre choix : ";
        cin>>choix;
    }
    while (choix<1 || choix>3);
}

void affichage::afficheTerrain(std::ofstream& fichier) const
{
    //if(!fichier.open())
    {
        cout<<"Le fichier ne s'est pas ouvert";
    }
    //else
    {
        //while(!fichier.eof())
        {
            char carac;
            cin>>carac;
            if(carac == '.')
            {
                cout<<" ";
            }
            else
            if(carac == '+')
            {
                cout<<endl;
            }
            else
            cout<<carac;
        }
    }
}

void affichage::afficheAventurier() const
{

}

void affichage::afficheMonstre() const
{

}

void affichage::afficheInfoAventurier(const aventurier &a) const
{
    cout<<"Points de vie : "<<a.getVie()<<'/n';
    cout<<"Points de force : "<<a.getForce()<<'/n';
    cout<<"Solidite armure : "<<a.getArmure().getPointSolidite()<<'/n';
    cout<<"Solidite epee : "<<a.getEpee().getPointSolidite()<<'/n';
}
