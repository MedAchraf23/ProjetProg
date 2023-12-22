#ifndef ARMURE_H_INCLUDED
#define ARMURE_H_INCLUDED

#include "equipement.h"

class armure : public equipement
{
public:
    armure(double pointSolidite);
    double attaqueMonstre(double poinforce);
    void absorbe(double f);
};


#endif // ARMURE_H_INCLUDED
