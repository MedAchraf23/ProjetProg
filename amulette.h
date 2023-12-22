#ifndef AMULETTE_H_INCLUDED
#define AMULETTE_H_INCLUDED

class amulette {
public:
    /**
    * @brief Constructeur de l'amulette
    * @param x Position a l'abscisse
    * @param y Position a l'ordonn�e
    */
    amulette(int x, int y);
    /**
    * @brief Renvoie la position en abscisse x de l'amulette
    * @param Un entier
    */
    int getX() const;
    /**
    * @brief Renvoie la position en ordonn�e y de l'amulette
    * @param Un entier
    */
    int getY() const;
private:
    int d_x, d_y;
};


#endif // AMULETTE_H_INCLUDED
