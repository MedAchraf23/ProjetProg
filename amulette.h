#ifndef AMULETTE_H_INCLUDED
#define AMULETTE_H_INCLUDED

class amulette {
public:
    amulette(int x, int y);
    int getX() const;
    int getY() const;
private:
    int d_x, d_y;
};


#endif // AMULETTE_H_INCLUDED
