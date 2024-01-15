#include "terrain.h"

terrain::terrain():d_terrainOBjet{}{};



void terrain::objetterrain(const string& path)
{
    ifstream fichier(path);
    string ligne;
    if (fichier.is_open()) {
        
    while (getline(fichier, ligne)) {
        vector<string> ligneConvertie;
        for (char caractere : ligne) { 
            if (caractere == ' ' || caractere == '\n' || caractere == '\t') {
                ligneConvertie.push_back("0");
            } else {
                ligneConvertie.push_back("1");
            }
        }
        d_terrainOBjet.push_back(ligneConvertie);
    }
    }else{    
        cout << "Erreur lors de l'ouverture du fichier." << endl;
    }

     fichier.close();
}


bool terrain::placerObjet(int x,int y)
{
     if(d_terrainOBjet[y][x]=="0")
       return true;
     else return false;       

}



vector<vector<string>>& terrain::getmatrice()
{
    return d_terrainOBjet;
} 