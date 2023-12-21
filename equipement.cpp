#include "equipement.h"

equipement::equipement(double pointSolidite):
    d_pointSolidite{pointSolidite} {}

double equipement::getPointSolidite () const
{
    return d_pointSolidite;
}

void equipement::setPointSolidite(double pointSolidite)
{
    d_pointSolidite = pointSolidite;
}

/*
void equipement::ramasserMonnaie()
{
    d_pointSolidite++;
}
*/
