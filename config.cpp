#include "config.h"
#include "afficheur.h"


Objet::Objet():d_tr{terrain{}},d_aventurier{100,100,epee{1},armure{100},"@",*this}
,d_monstreVoyant{monstreVoyant{100,100,100,"M",*this}}{};



void Objet::objetterrain(const string& path)
{
    d_tr.objetterrain(path);
    d_aventurier.setX(this->trouverCoordonnees().first);
    d_aventurier.setY(this->trouverCoordonnees().second);
    d_monstreVoyant.setX(this->trouverOccurrenceAleatoire(*this).first);
    d_monstreVoyant.setY(this->trouverOccurrenceAleatoire(*this).second);

}


aventurier Objet::getaventurier()const
{
    return d_aventurier;
}


monstreVoyant Objet::getmonstrevoyant()const
{
    return d_monstreVoyant;
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
        if(d_monstreVoyant.estVivant())
         this->deplacementmonstrevoyant();
        this->combat();
        aff.pointdevieaventurier(*this);
        aff.pointdevieMonstre(*this);

        if(aventurieragagner(x,y,aff) || aventurieDefaite(aff) )
        {
           Sleep(4000);
           system("cls");
           break;
        }

    }
}



void Objet::combat()
{
    if(intersection(d_monstreVoyant))
    {
    d_aventurier.subirDegat(d_monstreVoyant.attaque());
    d_monstreVoyant.perdPointsVie(d_aventurier.attaque());
    if(!d_monstreVoyant.estVivant())
       {
        afficheur::goto_xy(d_monstreVoyant.x(),d_monstreVoyant.y());
        cout<<" ";
        afficheur::goto_xy(d_aventurier.getX(),d_aventurier.getY());
        cout<<d_aventurier.getForme();
       }
    }
}

bool Objet::intersection(const monstre& Monstre) const
{

  return (d_aventurier.getX()==d_monstreVoyant.x()&&d_aventurier.getY()==d_monstreVoyant.y());
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



void Objet::afficheterrain(const string& path,const afficheur& aff)
{
    aff.afficheterrain(path,*this);
}



void Objet::afficheFichier(const string& path,fstream& fichier,const afficheur& aff)
{
    aff.afficheFichier(path,fichier);
}


bool Objet::aventurieragagner(int x,int y,const afficheur& aff)
{
   if(x>=d_tr.getmatrice()[y].size()-1 || y>=d_tr.getmatrice()[y].size()-1)
   {
    aff.messageVictoire();
    return true;
   }

   return false;
}




bool Objet::aventurieDefaite(const afficheur& aff)
{
   if(d_aventurier.getVie()<=0)
   {
    aff.messageDefaite();
    return true;
   }

   return false;
}


pair<int, int> Objet::trouverCoordonnees() {
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



  vector<pair<int, int>> Objet::trouverCoordonneesMonstre() {
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


pair<int, int> Objet::trouverOccurrenceAleatoire(Objet& config)const
{
    srand(static_cast<unsigned int>(time(0)));
    auto occurrences = config.trouverCoordonneesMonstre();
    if (occurrences.empty()) {
        return make_pair(-1, -1);
    }

    pair<int, int> coordAventurier = make_pair(config.getaventurier().getX(),config.getaventurier().getY());
    pair<int, int> coordChoisies;
    do {
        int index = rand() % occurrences.size();
        coordChoisies = occurrences[index];
    } while (coordChoisies == coordAventurier);

    return coordChoisies;
}

/*
void Objet::placerAmulette()
{
    srand(time(0));
    double valAleatoire;
    do
    {
        valAleatoire = rand()%100;
    }
    while(valAleatoire)
}
*/
