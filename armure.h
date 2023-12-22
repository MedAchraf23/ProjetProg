#ifndef ARMURE_H_INCLUDED
#define ARMURE_H_INCLUDED

#include "equipement.h"

class armure : public equipement
{
public:

    armure(double pointSolidite);
    /**
    * @brief Fait subir � l'armure les degat d'une attaque et renvoie les reste des points de force restant apres l'attaque
    * @param pointForce Points de force de l'attaque subit
    * @return Un r�el
    */
    double attaqueMonstre(double poinforce);
    /**
    * @brief Diminution des points de solidite de l'armure
    * @param f Points de force de l'attaque subit
    * @return Rien
    */
    void absorbe(double f);
};


#endif // ARMURE_H_INCLUDED
