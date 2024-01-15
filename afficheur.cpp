#include "afficheur.h"
#include "config.h"




afficheur::afficheur(){};

void afficheur::afficherMenu(const vector<string>& options, int optionSelectionnee)const  {
   system("cls");
  cout<<"----------MENU----------"<<endl;
   for (int i = 0; i < options.size(); ++i) {
        if (i == optionSelectionnee) {
            cout << "> " << options[i] << " <" << endl; 
        } else {
            cout << "  " << options[i] << endl;
        }
    }
}

int afficheur::mainmenu() const
{  
  
    vector<string> options = {"commencer la partie 1", "editer le terrain 2", "modifier aventurier 3", "Quitter"};
    int optionSelectionnee = 0;

    afficherMenu(options, optionSelectionnee);
   
    char touche;
    while (true) {
        touche = _getch();

        if (touche == '\r') { 
            cout << "Vous avez selectionne: " << options[optionSelectionnee] << endl;
            Sleep(2000);
            break;
        }

        if (touche == -32) { 
            touche = _getch(); 

            switch (touche) {
                case 72: 
                    optionSelectionnee = (optionSelectionnee > 0) ? optionSelectionnee - 1 : options.size() - 1;
                    break;
                case 80:
                    optionSelectionnee = (optionSelectionnee + 1) % options.size();
                    break;
            }
        }

        afficherMenu(options, optionSelectionnee);
    }
   system("cls");
   return optionSelectionnee;
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


void ouvrirFichier(const std::string& cheminFichier) {
    ShellExecute(NULL, "open", cheminFichier.c_str(), NULL, NULL, SW_SHOWDEFAULT);
}




void afficheur::afficheterrain(const string& path,Objet& objet)
{

    int option=mainmenu();
    string forme;
    switch(option)
    { 
      case 0: break;

      case 1: ouvrirFichier(path);
              break;
      
      case 2:
             cout<<"entrer une nouvelle forme pour l'aventurier:";
             cin>>forme;
             break;
      case 3:
             break;
    }
    system("cls");
    if(option==1 || option==3 )
       return ;
    if(option==2)
      objet.getaventurier().setforme(forme);   

    fstream fichier;
    afficheur::goto_xy();
    afficheur::afficheFichier(path,fichier);
    afficheur::ButtonQ();
    pointdevieaventurier(objet);
    pointdevieMonstre(objet);
    pointdevieMonstreAveugle(objet);

    auto position=objet.trouverCoordonnees();
    int x{objet.getaventurier().getX()},y{objet.getaventurier().getY()};
    
    string aventurier=objet.getaventurier().getForme();
    
   
    afficheur::goto_xy(x,y);
    cout<<aventurier; 

    affichemonstreVoyant(objet);
    
    affichemonstreAveugle(objet);

    afficheamulette(objet);

    afficheur::goto_xy(x+1,y);
    objet.DeplacerAventurier(x,y,aventurier,objet);

    fichier.close();
    system("cls");


}

void afficheur::affichemonstreVoyant(Objet& objet)const
{

    string monstrevoyant=objet.getmonstrevoyant().getforme(); 
    int monstrevoyantx{objet.getmonstrevoyant().x()};
    int monstrevoyanty{objet.getmonstrevoyant().y()};
    afficheur::goto_xy(monstrevoyantx,monstrevoyanty);
    cout<<monstrevoyant;
}


void afficheur::afficheamulette(Objet& objet)const
{
    string amulette=objet.getamulette().getforme();
    int posxamulette=objet.getamulette().getX();
    int posyamulette=objet.getamulette().getY();
    afficheur::goto_xy(posxamulette,posyamulette);
    cout<<amulette;

}


void afficheur::affichemonstreAveugle(Objet& objet)const
{
    string monstreAveugle=objet.getmonstreAveugle().getforme(); 
    int monstreAveuglex{objet.getmonstreAveugle().x()};
    int monstreAveugley{objet.getmonstreAveugle().y()};
    afficheur::goto_xy(monstreAveuglex,monstreAveugley);
    cout<<monstreAveugle;
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


void afficheur::messageDefaite(Objet& objet)const
{
    int columns=afficheur::positionnecurseur()/2;
    system("cls");
    string msg="GameOver !!";
    afficheur::goto_xy(columns-(msg.length()+1)/2,0);
    AfficheMsgConsole(msg,"RED");
}


void afficheur::messageDefaiteamulette(Objet& objet)const
{
    int columns=afficheur::positionnecurseur()/2;
    system("cls");
    string msg="GameOver !!vous n'avez pas pris l'amulette";
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
    static string ancienMsg;
    if (msg.length() < ancienMsg.length()) {
        msg += string(ancienMsg.length() - msg.length(), ' ');
    }

    afficheur::goto_xy(columns-(msg.length()+1),1);
    AfficheMsgConsole(msg,"BLUE");
    afficheur::goto_xy(objet.getaventurier().getX(),objet.getaventurier().getY());
    ancienMsg = msg;
}


void afficheur::pointdevieMonstre(Objet& objet)const
{
    
    int columns=afficheur::positionnecurseur();
    string msg="point de vie monstre Voyant:";
    if(objet.getmonstrevoyant().estVivant())
     msg+=to_string(objet.getmonstrevoyant().pointsVie());
    else msg+="0";
    static string ancienMsg;
    if (msg.length() < ancienMsg.length()) {
        msg += string(ancienMsg.length() - msg.length(), ' ');
    }
 
    afficheur::goto_xy(columns-(msg.length()+1),2);
    AfficheMsgConsole(msg,"BLUE");
    afficheur::goto_xy(objet.getaventurier().getX(),objet.getaventurier().getY());
    ancienMsg = msg;

}


void afficheur::pointdevieMonstreAveugle(Objet& objet)const
{
    
    int columns=afficheur::positionnecurseur();
    string msg="point de vie monstre Aveugle:";
    if(objet.getmonstreAveugle().estVivant())
     msg+=to_string(objet.getmonstreAveugle().pointsVie());
    else msg+="0";
    static string ancienMsg;
    if (msg.length() < ancienMsg.length()) {
        msg += string(ancienMsg.length() - msg.length(), ' ');
    }
 
    afficheur::goto_xy(columns-(msg.length()+1),3);
    AfficheMsgConsole(msg,"BLUE");
    afficheur::goto_xy(objet.getaventurier().getX(),objet.getaventurier().getY());
    ancienMsg = msg;

}



void afficheur::cacherCurseur() const
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(consoleHandle, &info);
    info.bVisible = false; // Cacher le curseur
    SetConsoleCursorInfo(consoleHandle, &info);
}

void afficheur::afficherCurseur() const
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(consoleHandle, &info);
    info.bVisible = true; 
    SetConsoleCursorInfo(consoleHandle, &info);
}



