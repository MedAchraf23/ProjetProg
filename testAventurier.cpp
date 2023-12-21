#include "doctest.h"
#include "aventurier.h"


TEST_CASE("La class aventurier fonctionne correctement") {

    SUBCASE("Le getVie fonctionne correctement") {
        double vie = 10;
        aventurier a{vie};
        REQUIRE_EQ(a.getVie(),vie);
    }
    SUBCASE("Le choix du deplacement est bien calcule") {
        double vie = 2, force = 3;
        int y = 11, x = 10;
        aventurier a{vie,force,x,y};
        int choix = 1;
        a.deplacer(choix);
        REQUIRE_EQ(a.getX(),x+1);
        REQUIRE_EQ(a.getY(),y);
    }
}
