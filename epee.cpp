#include"epee.h"

epee::epee(int pointSolidite):
    equipement{pointSolidite} {}

void epee::attaqueepee() const{
    d_pointSolidite--;
}
