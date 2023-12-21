#include "armure.h"

armure::armure(double pointSolidite):
    equipement{pointSolidite}
{}

double armure::attaqueMonstre(double pointforce)
{
    double f = pointforce*0.75;
    absorbe(f);
    return pointforce-f; //reste
}

void armure::absorbe(double f)
{
    double p = getPointSolidite();
    p = p - (f/2);
    if(p < 0)
    {
        p = 0;
    }
    setPointSolidite(p);
}

