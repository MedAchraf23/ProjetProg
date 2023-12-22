#ifndef EPEE_H_INCLUDED
#define EPEE_H_INCLUDED

#include "equipement.h"

class epee : public equipement {
public:
    /**
    * @brief Constructeur de l'epee
    * @param pointSolidite Les points de solidité de l'epee
    */
    epee(double pointSolidite);
    /**
    * @brief Diminue les points de solidite de l'epee
    * @return Rien
    */
    void attaqueEpee();
};

#endif // EPEE_H_INCLUDED
