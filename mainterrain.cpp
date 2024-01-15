#include "config.h"
#include "afficheur.h"




int main()
{
  
  Objet jeu{};
  afficheur aff{};
  string path="terrain.txt";
  jeu.objetterrain(path,jeu);
  jeu.afficheterrain(path,aff);
  
  return 0;

}
