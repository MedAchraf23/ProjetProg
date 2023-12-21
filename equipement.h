#ifndef EQUIPEMENT_H_INCLUDED
#define EQUIPEMENT_H_INCLUDED

class equipement
{
public:
    equipement(double pointSolidite);
    double getPointSolidite() const;
    void setPointSolidite(double pointSolidite);
    //void ramasserMonnaie();
protected:
    double d_pointSolidite;
};


#endif // EQUIPEMENT_H_INCLUDED
