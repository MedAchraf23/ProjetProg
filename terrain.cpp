#include "terrain.h"

/*
aventurier affichage::getAventurier() const
{
    return d_aventurier;
}

terrain affichage::getTerrain() const
{
    return d_terrain;
}

monstre affichage::getMonstre() const
{
    return d_monstre;
}
**/

void terrain::goto_xy(int x, int y)const
{
  HANDLE handle;
  COORD coordinates;
  handle = GetStdHandle(STD_OUTPUT_HANDLE);
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(handle, coordinates);
}

terrain::terrain(int largeur,int longeur):d_largeur{largeur},d_longeur{longeur},d_terrainOBjet{}{}

 void terrain::affiche_terrain(int x ,int y)const{

    int tmpx=x;
    string chaine="-----";
    int k=0,j,i=0;
    this->setcolorText(2);
    while(i<d_longeur)
    {  this->goto_xy(x,y);
       j=0;
       while(j<d_largeur)
       {
           if(d_terrainOBjet[i][j]=="1" && (i==0 || i==d_longeur-1))
            {
             if(j==0 || j==d_largeur-1)
              {  cout<<"     ";

              }
             else cout<<chaine;
            }
          else if(d_terrainOBjet[i][j]=="1")
               {
                if(j==d_largeur-1)
                 this->goto_xy(x-2,y);

                cout<<"-----";
                x+=7;
               }else {
                   this->goto_xy(x,y);
                   if(d_terrainOBjet[i][j]=="@")
                     this->setcolorText(4);
                   cout<<d_terrainOBjet[i][j];
                    this->setcolorText(2);
                   x+=5;
               }
           j++;
       }
      i++;
      cout<<endl;
      y+=1;
      x=tmpx;
    }

 }


int  terrain::get_largeur()const{return d_largeur;}
int  terrain::get_longeur()const{return d_longeur;}
void terrain::set_largeur(int x){d_largeur=x;}
void terrain::set_longeur(int y){d_longeur=y;}


void terrain::init_terrain()
{
    d_terrainOBjet.resize(d_longeur, vector<string>(d_largeur));

    for(int i=0;i<d_largeur;i++)
    {
      d_terrainOBjet[0][i]="1";
      d_terrainOBjet[d_longeur-1][i]="1";

    }

    for(int i=0;i<d_longeur;i++)
    {
      d_terrainOBjet[i][0]="1";
      d_terrainOBjet[i][d_largeur-1]="1";
    }


    for(int i=1;i<d_longeur-1;i++)
    {
     for(int j=1;j<d_largeur-1;j++)
      {
          d_terrainOBjet[i][j]=" ";
      }
    }

}

bool terrain::objet_terrain(int x,int y,const string& ch){

  if(d_terrainOBjet[y][x]!="1")
   {
    d_terrainOBjet[y][x]=ch;
    return true;}
  else
    return false;
}




void terrain::terrain_objet_update(int x,int y ,const string& ch,int x1,int y1)
{
 this->goto_xy((x+1)*5-3+x1, y+y1);
 this->setcolorText(4);
 char key;
 bool placed;
  while ((key = _getch()) != 'q') {
            switch (key) {
                case 49:
                    if((placed=this->objet_terrain(x,y-1,"@")) && placed==true )
                    {this->goto_xy((x+1)*5-3+x1, y+y1);
                    cout <<" ";
                    y--;}
                    break;
                case 50:
                    if((placed=this->objet_terrain(x,y+1,"@")) && placed==true )
                    {this->goto_xy((x+1)*5-3+x1, y+y1);
                    cout <<" ";
                    y++;}
                    break;
                case 51:
                    if((placed=this->objet_terrain(x+1,y,"@")) && placed==true )
                    {this->goto_xy((x+1)*5-3+x1, y+y1);
                    cout <<" ";
                    x++;}
                    break;
                case 52:
                    if((placed=this->objet_terrain(x-1,y,"@")) && placed==true )
                    {this->goto_xy((x+1)*5-3+x1, y+y1);
                    cout <<" ";
                    x--;}
                    break;
                case 53:
                    if((placed=this->objet_terrain(x-1,y-1,"@")) && placed==true )
                    {this->goto_xy((x+1)*5-3+x1, y+y1);
                    cout <<" ";
                    x--;
                    y--;}
                    break;
                case 54:
                    if((placed=this->objet_terrain(x+1,y-1,"@")) && placed==true )
                    {this->goto_xy((x+1)*5-3+x1, y+y1);
                    cout <<" ";
                    x++;
                    y--;}
                    break;
                case 55:
                    if((placed=this->objet_terrain(x-1,y+1,"@")) && placed==true )
                    {this->goto_xy((x+1)*5-3+x1, y+y1);
                    cout <<" ";
                    x--;
                    y++;}
                    break;
                case 56:
                    if((placed=this->objet_terrain(x+1,y+1,"@")) && placed==true )
                    {this->goto_xy((x+1)*5-3+x1, y+y1);
                    cout <<" ";
                    x++;
                    y++;}
                    break;
            }


        this->goto_xy((x+1)*5-3+x1, y+y1);
        cout <<ch;
    }
}


void terrain::setcolorText(int color)const
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);


}
