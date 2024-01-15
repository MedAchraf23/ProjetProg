#ifndef AMULETTE_H_INCLUDED
#define AMULETTE_H_INCLUDED
#include "include.h"

class amulette {
public:
    amulette(int x, int y,const string& forme);
    int getX() const;
    int getY() const;
    string getforme() const;
    void setX(int x);
    void setY(int y);
private:
    int d_x, d_y;
    string d_forme;
};


#endif // AMULETTE_H_INCLUDED
