#include "amulette.h"

amulette::amulette(int x, int y, const string& forme):
    d_x{x}, d_y{y},d_forme{forme}
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



string amulette::getforme() const
{

    return d_forme;
}

void amulette::setX(int x)
{
  d_x=x;
}
void amulette::setY(int y)
{
    d_y=y;
}