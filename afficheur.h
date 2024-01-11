#include "include.h"



class Objet;

class afficheur{
 public:
 afficheur();
 void afficheterrain(const string& path,Objet& objet)const;
 void afficheFichier(const string& path,fstream& fichier)const;
 static void goto_xy(int x=0, int y=0);
 void ButtonQ()const;
 void messageVictoire()const;
 void messageDefaite()const;
 void pointdevieaventurier(Objet& objet)const;
 void pointdevieMonstre(Objet& objet)const;
 void AfficheMsgConsole(string msg, string color) const;
 void afficheMenu(int choix) const;
 static int  positionnecurseur();

};
