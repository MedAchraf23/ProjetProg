#ifndef EPEE_H_INCLUDED
#define EPEE_H_INCLUDED

#include "equipement.h"

class epee : public equipement {
public:

    epee(double pointSolidite);
    void attaqueEpee();
};

#endif // EPEE_H_INCLUDED
