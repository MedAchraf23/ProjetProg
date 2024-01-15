#include "include.h"



class Objet;

class afficheur{
 public:
 afficheur();
 void afficheterrain(const string& path,Objet& objet);
 void afficheFichier(const string& path,fstream& fichier)const;
 static void goto_xy(int x=0, int y=0);
 void ButtonQ()const;
 void messageVictoire()const;
 void messageDefaite(Objet& objet)const;
 void pointdevieaventurier(Objet& objet)const;
 void pointdevieMonstre(Objet& objet)const;
 void AfficheMsgConsole(string msg, string color) const;
 void afficheamulette(Objet& objet)const;
 void pointdevieMonstreAveugle(Objet& objet)const;
 void affichemonstreAveugle(Objet& objet)const;
void messageDefaiteamulette(Objet& objet)const;
 void affichemonstreVoyant(Objet& objet)const;
 
 void cacherCurseur() const;
 void afficherCurseur() const;
 int mainmenu() const;
 void afficherMenu(const vector<string>& options, int optionSelectionnee)const;
 static int positionnecurseur();
 
};
