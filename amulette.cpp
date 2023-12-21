#include "amulette.h"

amulette::amulette(int x, int y):
    d_x{x}, d_y{y}
{

}

int amulette::getX() const
{
    return d_x;
}

int amulette::getY() const
{
    return d_y;
}

bool amulette::amuletteRamasse(const aventurier& a) const
{
    if(d_x == a.getX() && d_y == a.getY())
    {
        return true;
    }
    else
        return false;
}
