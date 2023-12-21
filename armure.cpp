#include"armure.h"

armure::armure(int pointSolidite):
    equipement{pointSolidite} {}

int armure::attaquemonstre(int pointforce)const{
    f{pointforce*0.75};
    absorbe(f);
    int reste{pointforce-f};
    return reste;
}

void armure::absorbe(double f) const{
    p{pointSolidite()};
    p = p - pointforce/2;
    if(p<0) p{0};
    setPointSolidite(p);

}

