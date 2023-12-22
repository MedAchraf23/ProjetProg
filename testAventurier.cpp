//#include "doctest.h"
//#include "aventurier.h"
//
//
//TEST_CASE("La class aventurier fonctionne correctement")
//{
//    epee epee{15.0};
//    armure armure{17.0};
//    SUBCASE("Construction avec toutes les informations")
//    {
//        double vie = 10.0, force = 13.0;
//        aventurier a{vie,force,epee,armure};
//        REQUIRE_EQ(a.getVie(),vie);
//        REQUIRE_EQ(a.getForce(),force);
//        REQUIRE_EQ(a.getX(),xInitial);
//        REQUIRE_EQ(a.getY(),yInitial);
//    }
//
//    SUBCASE("Deplacement vers case du haut")
//    {
//        double vie = 10.0, force = 14.0;
//        aventurier a{vie,force,epee,armure};
//        int choix = 1;
//        a.deplacer(choix);
//        REQUIRE_EQ(a.getX(),xInitial+1);
//        REQUIRE_EQ(a.getY(),yInitial);
//    }
//
//    SUBCASE("Deplacement vers la case diagonale Bas Gauche")
//    {
//        double vie = 10.0, force = 14.0;
//        aventurier a{vie,force,epee,armure};
//        int choix = 8;
//        a.deplacer(choix);
//        REQUIRE_EQ(a.getX(),xInitial-1);
//        REQUIRE_EQ(a.getY(),yInitial-1);
//    }
//
//    /*
//    SUBCASE("Rester sur place")
//    {
//
//    }*/
//
//    SUBCASE("Aventurier qui subit des degat affecte ses points de vie")
//    {
//        double vie = 10.0, force = 14.0;
//        aventurier a{vie,force,epee,armure};
//        double f = 4.0;
//        a.subirDegat(f);
//        REQUIRE_LT(a.getVie(),vie);
//    }
//
//    SUBCASE("Verification si l'aventurier possede bien l'amulette")
//    {
//        double vie = 10.0, force = 14.0;
//        aventurier a{vie,force,epee,armure};
//        int xAmulette = xInitial, yAmulette = yInitial;
//        amulette amulette{xAmulette,yAmulette};
//        REQUIRE_UNARY(a.possedeAmulette(amulette));
//    }
//
//}
