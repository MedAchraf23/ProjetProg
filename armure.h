#ifndef ARMURE_H_INCLUDED
#define ARMURE_H_INCLUDED

class armure : public equipement {
public:

    armure(int pointSolidite);
    void attaquemonstre(int poinforce)const;
    void absorbe(int f) const;


};


#endif // ARMURE_H_INCLUDED
