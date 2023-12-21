#ifndef TERRAIN
#define TERRAIN
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <conio.h>

using namespace std;

class terrain
{
  public:
  void goto_xy(int x=0, int y=0);
  terrain(int largeur,int longeur);
  void affiche_terrain();
  void init_terrain();
  int get_largeur();
  int get_longeur();
  void set_largeur(int x);
  void set_longeur(int y);
  bool objet_terrain(int x,int y,const string& ch);
  void terrain_objet_update(int x,int y ,const string& ch);
  private:
   int d_largeur,d_longeur;
   vector<vector<string>> d_terrainOBjet;
};


#endif
