#include<amulette.h>

amulette::amulette(const position& p):
    d_position{position} {}

position amulette::position() const{
return d_position;
}

bool amulette::amuletteramassé() const {
    return d_position==aventurier.postion();

}
