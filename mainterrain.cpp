#include "terrain.h"

using namespace std;


int main()
{

 terrain chateau{20,20};
 chateau.init_terrain();
 int x=1,y=1;
 bool placed;
 chateau.objet_terrain(x,y,"@");
 int ax=10,ay=10;
 chateau.affiche_terrain(ax,ay);
 chateau.terrain_objet_update(1,1,"@",ax,ay);
    return 0;
}
