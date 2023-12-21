#ifndef AMULETTE_H_INCLUDED
#define AMULETTE_H_INCLUDED

class amulette {
public:
    amulette(const position& p);
    position position() const;
    bool amuletteramassé() const;
private:
    position d_position;

};


#endif // AMULETTE_H_INCLUDED
