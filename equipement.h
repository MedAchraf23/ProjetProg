#ifndef EQUIPEMENT_H_INCLUDED
#define EQUIPEMENT_H_INCLUDED

class equipement
{
public:
        /**
    * @brief Constructeur de la class abstraite equipement
    * @param pointSolidite Les points de solidite des ses sous class
    */
    equipement(double pointSolidite);
    /**
    * @brief Renvoie les points de solidité d'un equipement
    * @return Un reel
    */
    double getPointSolidite() const;
    /**
    * @brief Change les points de solidité d'un equipement
    * @param pointSolidite
    * @return Rien
    */
    void setPointSolidite(double pointSolidite);
protected:
    double d_pointSolidite;
};


#endif // EQUIPEMENT_H_INCLUDED
