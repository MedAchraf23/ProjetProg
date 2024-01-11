#include "include.h"
#include "terrain.h"
#include "aventurier.h"
#include "monstreVoyant.h"


class afficheur;

class Objet {
public:
    Objet() ;
    static void goto_xy(int x=0, int y=0);
    void ButtonQ();
    void DeplacerAventurier(int x, int y, const string& objet ,Objet& conf);
    void deplacerSiPossible(int& x, int& y, int newX, int newY, const string& objet);
    void afficheterrain(const string& path,const afficheur& aff);
    void afficheFichier(const string& path,fstream& fichier,const afficheur& aff);
    void objetterrain(const string& path);
    bool aventurieragagner(int x,int y,const afficheur& aff);
    bool aventurieDefaite(const afficheur& aff);
    pair<int, int>  trouverCoordonnees();
    aventurier getaventurier()const;
    monstreVoyant getmonstrevoyant()const;
    vector<pair<int, int>> trouverCoordonneesMonstre();
    pair<int, int> trouverOccurrenceAleatoire(Objet& config)const;
    void deplacementmonstrevoyant();
    bool intersection(const monstre& Monstre)const;
    void combat();
private:
    terrain d_tr;
    aventurier d_aventurier;
    monstreVoyant d_monstreVoyant;
};


