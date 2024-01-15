#ifndef TERRAIN
#define TERRAIN
#include "include.h"


class terrain
{
  public:
  terrain();
  void objetterrain(const string& path);
  bool placerObjet(int x,int y);
  vector<vector<string>>& getmatrice(); 
  private:
   vector<vector<string>> d_terrainOBjet;
   
};


#endif
