#ifndef AMULETTE_H_INCLUDED
#define AMULETTE_H_INCLUDED

#include "aventurier.h"

class amulette {
public:
    amulette(int x, int y);
    int getX() const;
    int getY() const;
    bool amuletteRamasse(const aventurier& a) const;
private:
    int d_x, d_y;
};


#endif // AMULETTE_H_INCLUDED
