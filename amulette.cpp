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

