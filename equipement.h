#ifndef EQUIPEMENT_H_INCLUDED
#define EQUIPEMENT_H_INCLUDED

class equipement {
public:

    equipement(int pointSolidite);
    int getPointSolidite () const;
    void setPointSolidite () const;
    void ramassermonnaie() const;



private:
    int d_pointSolidite ;

};


#endif // EQUIPEMENT_H_INCLUDED
