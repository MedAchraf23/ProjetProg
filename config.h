#include "include.h"
#include "terrain.h"
#include "aventurier.h"
#include "monstreVoyant.h"
#include "monstreAveugle.h"


class afficheur;

class Objet {
public:
    Objet() ;
    static void goto_xy(int x=0, int y=0);
    void ButtonQ();
    void DeplacerAventurier(int x, int y, const string& objet ,Objet& conf);
    void deplacerSiPossible(int& x, int& y, int newX, int newY, const string& objet);
    void afficheterrain(const string& path,afficheur& aff);
    void afficheFichier(const string& path,fstream& fichier,const afficheur& aff);
    void objetterrain(const string& path,Objet& config);
    bool aventurierasortie(const afficheur& aff);
    bool aventurieDefaite(const afficheur& aff);
    pair<int, int>  trouverCoordonneesaventurier();
    bool monstreA_monstreV() const;
    aventurier& getaventurier();
    monstreVoyant& getmonstrevoyant();
    monstreAveugle& getmonstreAveugle();
    amulette& getamulette();
    vector<pair<int, int>> trouverCoordonnees();
    void deplacementmonstrevoyant();
    void deplacementmonstreAveugle();
    bool amulette_monstre()const;
    bool amulette_aventurier();
    bool monstre_monstre();
    bool intersection(const monstre& Monstre)const;
    void combat(monstre& monstre);
private:
    terrain d_tr;
    aventurier d_aventurier;    
    monstreVoyant d_monstreVoyant;  
    monstreAveugle d_monstreAveugle;
    amulette d_amulette;
};

