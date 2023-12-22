#ifndef AVENTURIER_H_INCLUDED
#define AVENTURIER_H_INCLUDED

#include "equipement.h"
#include "epee.h"
#include "armure.h"
#include "amulette.h"

const int xInitial = 10;
const int yInitial = 10;

class aventurier
{
public:
    /**
    * @brief Constructeur de l'aventurier
    * @param Vie Points de vie de l'aventurier
    * @param Force Points de force de l'aventurier
    * @param Epee
    * @param Armure
    */
    aventurier(double vie, double force, const epee& epee, const armure& armure);
    /**
    * @brief Renvoie les points de vie de l'aventurier
    * @return Un réel
    */
    double getVie() const;
    /**
    * @brief Renvoie les points de force de l'aventurier
    * @return Un réel
    */
    double getForce() const;
    /**
    * @brief Renvoie l'abscisse x
    * @return Un entier
    */
    int getX() const;
    /**
    * @brief Renvoie l'ordonnée y
    * @return Un entier
    */
    int getY() const;
    /**
    * @brief Change l'abscisse
    * @param x La nouvelle abscisse à remplacer
    * @return Rien
    */
    void setX(int x);
    /**
    * @brief Change l'ordonnée
    * @param y La nouvelle ordonnée à remplacer
    * @return Rien
    */
    void setY(int y);
    /**
    * @brief Renvoie l'epee de l'aventurier
    * @return Une epee
    */
    epee getEpee() const;
    /**
    * @brief Renvoie l'armure de l'aventurier
    * @return Une armure
    */
    armure getArmure() const;
    /**
    * @brief Change les coordonnées x et y de l'aventurier
    * @param choix Le choix de deplacement
    * @return Rien
    */
    void deplacer(int choix);
    /**
    * @brief Diminue les points de vie de l'aventurier
    * @param f Les points de forces de l'attaque subit
    * @return Rien
    */
    void subirDegat(double f);
    /**
    * @brief L'aventurier attaque un monstre avec son epee
    * @param f Les points de forces de l'attaque
    * @return Rien
    */
    void attaque(double f);
    /**
    * @brief Verifie si l'aventurier se trouve au meme endroit que l'amulette
    * @param a L'amulette a ramasse
    * @return Un booleen
    */
    bool possedeAmulette(const amulette& a) const;
private:
    double d_pointsVie;
    double d_pointsForce;
    int d_x, d_y;
    epee d_epee;
    armure d_armure;
    //boursePieces d_boursePieces;
};

#endif // AVENTURIER_H_INCLUDED
