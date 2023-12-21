#include <iostream>
#include <string>
#include <vector>
#include "terrain.h"
#include <windows.h>
#include <conio.h>
using namespace std;


int main()
{

 terrain chateau{10,10};
 chateau.init_terrain();
 int x=1,y=1;
 bool placed;
 chateau.objet_terrain(x,y,"@");
 chateau.affiche_terrain();
 chateau.terrain_objet_update(x,y,"@");


    return 0;
}
