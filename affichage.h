#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include <ostream>

class affichage
{
public:
    affichage(const ostream& ost, const aventurier& aventurier, const terrain& terrain, const monstre& monstre, const amulette& amulette);
    aventurier getAventurier() const;
    terrain getTerrain() const;
    monstre getMonstre() const;
    void afficheMenu() const;
    void afficheTerrain() const;
    void afficheAventurier() const;
    void afficheMonstre() const;
    void afficheConfigAventurier() const;
    void afficheDesTouchesDeplacement() const;
    void afficheAmulette() const;
private:
    ostream d_ost;
    aventurier d_aventurier;
    terrain d_terrain;
    monstre d_monstre;
    amulette d_amulette;
};


#endif // AFFICHAGE_H_INCLUDED
