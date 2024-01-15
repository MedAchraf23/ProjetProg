#include "config.h"
#include "afficheur.h"


Objet::Objet():d_tr{terrain{}},d_aventurier{100,100,epee{1},armure{100},"@",*this}
,d_monstreVoyant{monstreVoyant{5000,100,12,6,100,"M",*this}},d_amulette{59,12,"$"},d_monstreAveugle(1000,100,64,10,100,"A",*this){};



void Objet::objetterrain(const string& path, Objet& config)
{   
    d_tr.objetterrain(path);
    auto occurrences=config.trouverCoordonnees();
    d_aventurier.setX(trouverCoordonneesaventurier().first);
    d_aventurier.setY(trouverCoordonneesaventurier().second);


}


aventurier& Objet::getaventurier()
{
    return d_aventurier;
}


monstreVoyant& Objet::getmonstrevoyant()
{
    return d_monstreVoyant;
}

monstreAveugle& Objet::getmonstreAveugle()
{
    return d_monstreAveugle;
}


void Objet::DeplacerAventurier(int x, int y, const string& objet ,Objet& conf) {
    char key;
    afficheur aff{};

    while ((key = _getch()) != 'q') {
        switch (key) {
            case 49: 
                deplacerSiPossible(x, y, x + 1, y, objet);
                break;
            case 50: 
                deplacerSiPossible(x, y, x - 1, y, objet);
                break;
            case 51: 
                deplacerSiPossible(x, y, x, y + 1, objet);
                break;
            case 52: 
                deplacerSiPossible(x, y, x, y - 1, objet);
                break;
            case 53: 
                deplacerSiPossible(x, y, x-1, y - 1,objet);
                break;
            case 54: 
                deplacerSiPossible(x, y, x+1, y+1, objet);
                break;
            case 55: 
                deplacerSiPossible(x, y, x+1, y-1, objet);
                break;
            case 56: 
                deplacerSiPossible(x, y, x-1, y+1, objet);
                break;

        }

        d_aventurier.setX(x);
        d_aventurier.setY(y);
    

        aff.cacherCurseur(); 
        
        if(d_monstreVoyant.estVivant())
         { 
            this->deplacementmonstrevoyant();
            this->combat(d_monstreVoyant);
         }
          if(d_monstreAveugle.estVivant())
         {
           this->deplacementmonstreAveugle();
           this->combat(d_monstreAveugle);
         }

        if(!amulette_monstre() && !amulette_aventurier())
        {
            aff.afficheamulette(*this);
        }
         if(!monstreA_monstreV() && d_monstreAveugle.estVivant())
         {
             aff.affichemonstreAveugle(*this);
         }
         if(d_monstreVoyant.estVivant())
           aff.affichemonstreVoyant(*this); 

         

        aff.pointdevieaventurier(*this);
        aff.pointdevieMonstre(*this);
        aff.pointdevieMonstreAveugle(*this);
        aff.afficherCurseur();
        
        if(aventurierasortie(aff) || aventurieDefaite(aff) )
        {
           Sleep(4000);
           system("cls");
           break;
        }
    
    }
}



bool Objet::amulette_monstre() const
{
    int posxamulette=d_amulette.getX();
    int posyamulette=d_amulette.getY();
    int posxmonstrevoyant=d_monstreVoyant.x();
    int posymonstrevoyant=d_monstreVoyant.y();
    int posxmonstreaveugle=d_monstreAveugle.x();
    int posymonstreaveugle=d_monstreAveugle.x();
    return (posxamulette==posxmonstrevoyant&& posyamulette==posymonstrevoyant) || (posxmonstreaveugle==posxamulette && posymonstreaveugle==posyamulette);

}


bool Objet::amulette_aventurier() 
{
     if(d_aventurier.possedeAmulette())
      return true;

     int posxamulette=d_amulette.getX();
     int posyamulette=d_amulette.getY();
     int posxaventurier=d_aventurier.getX();
     int posyaventurier=d_aventurier.getY();
     
     if((posxamulette==posxaventurier) && (posyamulette==posyaventurier))
     {
       d_aventurier.setpossedeAmulette();
       return true;
     }

     return false;
}



void Objet::combat(monstre& monstre)
{
    if(intersection(monstre))
    {
    d_aventurier.subirDegat(monstre.attaque());
    monstre.perdPointsVie(d_aventurier.attaque());
    if(!monstre.estVivant())
       {
        afficheur::goto_xy(monstre.x(),monstre.y());
        cout<<" ";
        afficheur::goto_xy(d_aventurier.getX(),d_aventurier.getY());
        cout<<monstre.getforme();
       }
    }
}


bool Objet::monstreA_monstreV() const
{
   return d_monstreAveugle.x()==d_monstreVoyant.x() && d_monstreAveugle.y()==d_monstreVoyant.y();
}


bool Objet::intersection(const monstre& Monstre) const
{

  return (d_aventurier.getX()==Monstre.x()&&d_aventurier.getY()==Monstre.y());
}



void Objet::deplacementmonstrevoyant()
{
  int posinitialx=d_monstreVoyant.x();
  int posinitisly=d_monstreVoyant.y();
  
  d_monstreVoyant.seDeplace(d_aventurier.getX(),d_aventurier.getY());
  if(d_tr.getmatrice()[d_monstreVoyant.y()][d_monstreVoyant.x()]=="1")
    {
        d_monstreVoyant.setX(posinitialx);
        d_monstreVoyant.setY(posinitisly);

    }else {
        
        afficheur::goto_xy(posinitialx,posinitisly);
        cout<<" ";
        afficheur::goto_xy(d_monstreVoyant.x(), d_monstreVoyant.y());
        cout<<d_monstreVoyant.getforme();
        afficheur::goto_xy(d_aventurier.getX(),d_aventurier.getY());
        cout<<d_aventurier.getForme();
        
    }

}


void Objet::deplacementmonstreAveugle()
{
  int posinitialx=d_monstreAveugle.x();
  int posinitisly=d_monstreAveugle.y();
  
  d_monstreAveugle.seDeplace();
  int newx=d_monstreAveugle.x();
  int newy=d_monstreAveugle.y();
  if(newy>d_tr.getmatrice().size() || newx>d_tr.getmatrice()[newy].size()-2 || d_tr.getmatrice()[newy][newx]=="1")
  {
        d_monstreAveugle.setX(posinitialx);
        d_monstreAveugle.setY(posinitisly);

    }else 
    {
        afficheur::goto_xy(posinitialx,posinitisly);
        cout<<" ";
        afficheur::goto_xy(newx,newy);
        cout<<d_monstreAveugle.getforme();
        afficheur::goto_xy(d_aventurier.getX(),d_aventurier.getY());
        cout<<d_aventurier.getForme();
    }

}




void Objet::deplacerSiPossible(int& x, int& y, int newX, int newY, const string& objet) {
    if (d_tr.placerObjet(newX, newY)) {
        afficheur::goto_xy(x, y);
        cout<<" ";
        afficheur::goto_xy(newX, newY);
        cout<< objet;
        x = newX;
        y = newY;
    }
}



void Objet::afficheterrain(const string& path,afficheur& aff)
{
    aff.afficheterrain(path,*this);
}



amulette& Objet::getamulette()
{
    return d_amulette;
}
 

void Objet::afficheFichier(const string& path,fstream& fichier,const afficheur& aff)
{
    aff.afficheFichier(path,fichier);
}


bool Objet::aventurierasortie(const afficheur& aff) 
{
   bool cond=false;
   int posx=d_aventurier.getX();
   int posy=d_aventurier.getY();
   if(posx>=d_tr.getmatrice()[posy].size()-1 || posy>=d_tr.getmatrice().size()-1)
   {
   
    if(!d_aventurier.possedeAmulette())
      aff.messageDefaiteamulette(*this);
    else {
        aff.messageVictoire();
    
    }

    cond=true;
   }

   return cond;
}




bool Objet::aventurieDefaite(const afficheur& aff) 
{
   if(d_aventurier.getVie()<=0)
   {
    aff.messageDefaite(*this);
    return true;
   }

   return false;
}



pair<int, int> Objet::trouverCoordonneesaventurier() {
    for (int y = 0; y < d_tr.getmatrice().size(); y++) {
        for (int x = 0; x < d_tr.getmatrice()[y].size(); x++) {
            if (x + 2 < d_tr.getmatrice()[y].size() &&
                d_tr.getmatrice()[y][x] == "0" &&
                d_tr.getmatrice()[y][x + 1] == "1" &&
                d_tr.getmatrice()[y][x + 2] == "0") {

                return make_pair(x+2, y);
            }
        }
    }

    return make_pair(-1, -1);
}



vector<pair<int, int>> Objet::trouverCoordonnees()  {
    vector<pair<int, int>> occurrences;
    bool envoyerPremierZero = true;

    for (int y = 0; y < d_tr.getmatrice().size(); y++) {
        envoyerPremierZero = true;
        for (int x = 0; x < d_tr.getmatrice()[y].size(); x++) {
            if (x + 2 < d_tr.getmatrice()[y].size() &&
                d_tr.getmatrice()[y][x] == "0" &&
                d_tr.getmatrice()[y][x + 1] == "1" &&
                d_tr.getmatrice()[y][x + 2] == "0") {
                
                if (envoyerPremierZero) {
                    occurrences.push_back(make_pair(x+2, y)); 
                } else {
                    occurrences.push_back(make_pair(x, y)); 
                }
                envoyerPremierZero = !envoyerPremierZero;
            }

        }
    }

    return occurrences;
}








