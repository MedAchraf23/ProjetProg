#include<equipement.h>

equipement::equipement(int pointSolidite):
    d_pointSolidite{pointSolidite} {}

int equipement::getPointSolidite () const{
return d_pointSolidite;
}
void equipement::setPointSolidite (int pointSolidite) const{
d_pointSolidite{poinSolidite};
}

void equipement::ramassermonnaie() const{
d_poinSolidite++;
}
