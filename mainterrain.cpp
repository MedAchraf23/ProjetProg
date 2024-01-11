#include "config.h"
#include "afficheur.h"




int main()
{
  Objet jeu{};
  string path="terrain.txt";
  jeu.objetterrain(path);
  jeu.afficheterrain(path,afficheur{});
  
  return 0;

}
