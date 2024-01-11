//#include "doctest.h"
//#include "aventurier.h"
//#include "config.h"
//
//
//
//TEST_CASE("La class aventurier fonctionne correctement")
//{
//    epee epee{15.0};
//    armure armure{17.0};
//    string forme = "@";
//    Objet config{};
//    int xInitial = 10;
//    int yInitial = 8;
//    SUBCASE("Construction avec toutes les informations")
//    {
//        double vie = 10.0, force = 13.0;
//        aventurier a{vie,force,epee,armure, forme, config};
//        REQUIRE_EQ(a.getVie(),vie);
//        REQUIRE_EQ(a.getForce(),force);
//    }
//    SUBCASE("Verif coordonnees")
//    {
//        double vie = 10.0, force = 13.0;
//        aventurier a{vie,force,epee,armure, forme, config};
//        a.setX(xInitial);
//        a.setY(yInitial);
//        REQUIRE_EQ(a.getX(),xInitial);
//        REQUIRE_EQ(a.getY(),yInitial);
//    }
//
//
//    SUBCASE("Aventurier qui subit des degat affecte ses points de vie")
//    {
//        double vie = 10.0, force = 14.0;
//        aventurier a{vie,force,epee,armure, forme, config};
//        double f = 4.0;
//        a.subirDegat(f);
//        REQUIRE_LT(a.getVie(),vie);
//    }
//
//    SUBCASE("Verification si l'aventurier possede bien l'amulette")
//    {
//        double vie = 10.0, force = 14.0;
//        aventurier a{vie,force,epee,armure, forme, config};
//        int xAmulette = xInitial, yAmulette = yInitial;
//        amulette amulette{xAmulette,yAmulette};
//        REQUIRE_UNARY(a.possedeAmulette(amulette));
//    }
//
//}
