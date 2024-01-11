#include "afficheur.h"
#include "config.h"




afficheur::afficheur(){};


void afficheur::afficheMenu(int choix) const
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

void afficheur::goto_xy(int x, int y)
{
  HANDLE handle;
  COORD coordinates;
  handle = GetStdHandle(STD_OUTPUT_HANDLE);
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(handle, coordinates);

}


int  afficheur::positionnecurseur()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    if (!GetConsoleScreenBufferInfo(hStdout, &csbi)) {
        cout << "GetConsoleScreenBufferInfo echouee" <<endl;

    }
    return csbi.srWindow.Right - csbi.srWindow.Left;
}


void afficheur::ButtonQ()const
{

    int columns = afficheur::positionnecurseur();
    string msg="appuyer sur q pour quitter";
    afficheur::goto_xy(columns-msg.length()+1,0);
    cout<<msg;
}



void afficheur::afficheterrain(const string& path,Objet& objet)const
{
    system("cls");
    fstream fichier;
    afficheur::goto_xy();
    afficheur::afficheFichier(path,fichier);
    afficheur::ButtonQ();
    this->pointdevieaventurier(objet);
    this->pointdevieMonstre(objet);

    auto position=objet.trouverCoordonnees();
    int x{objet.getaventurier().getX()},y{objet.getaventurier().getY()};

    string aventurier=objet.getaventurier().getForme();
    string monstrevoyant=objet.getmonstrevoyant().getforme();
    afficheur::goto_xy(x,y);
    cout<<aventurier;

    int monstrevoyantx{objet.getmonstrevoyant().x()};
    int monstrevoyanty{objet.getmonstrevoyant().y()};

    afficheur::goto_xy(monstrevoyantx,monstrevoyanty);
    cout<<monstrevoyant;
    afficheur::goto_xy(x+1,y);
    objet.DeplacerAventurier(x,y,aventurier,objet);

    fichier.close();
    system("cls");

}



void afficheur::afficheFichier(const string& path,fstream& fichier)const
{
    string ligne;
    fichier.open(path);
    if (fichier.is_open()) {

        while (getline(fichier, ligne)) {
        cout << ligne << endl;
       }
    }else {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
    }
}





void afficheur::AfficheMsgConsole(string msg, string color) const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorCode;

    if (color == "RED") {
        colorCode = FOREGROUND_RED;
    } else if (color == "GREEN") {
        colorCode = FOREGROUND_GREEN;
    } else if (color == "BLUE") {
        colorCode = FOREGROUND_BLUE;
    }

    SetConsoleTextAttribute(hConsole, colorCode);
    cout << msg;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}


void afficheur::messageDefaite()const
{
    int columns=afficheur::positionnecurseur()/2;
    system("cls");
    string msg="GameOver !!";
    afficheur::goto_xy(columns-(msg.length()+1)/2,0);
    AfficheMsgConsole(msg,"RED");
}

void afficheur::messageVictoire()const
{
    int columns=afficheur::positionnecurseur()/2;
    system("cls");
    string msg="Felicitations! Vous avez gagne !!";
    afficheur::goto_xy(columns-(msg.length()+1)/2,0);
    AfficheMsgConsole(msg,"GREEN");
}


void afficheur::pointdevieaventurier(Objet& objet)const
{
    int columns=afficheur::positionnecurseur();
    string msg=" point de vie aventurier:"+to_string(static_cast<int>(objet.getaventurier().getVie()));
    afficheur::goto_xy(columns-(msg.length()+1),1);
    AfficheMsgConsole(msg,"BLUE");
}


void afficheur::pointdevieMonstre(Objet& objet)const
{
    int columns=afficheur::positionnecurseur();
    string msg;
    if(!objet.getmonstrevoyant().estVivant())
    {
        msg="point de vie monstre:0  ";
    }else {msg="point de vie monstre:"+to_string(objet.getmonstrevoyant().pointsVie());}
    afficheur::goto_xy(columns-(msg.length()+1),2);
    AfficheMsgConsole(msg,"BLUE");
}


