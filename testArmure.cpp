//#include "armure.h"
//#include "doctest.h"
//
//TEST_CASE("La class armure fonctionne correctement") {
//
//    SUBCASE("Le reste des points de force d'une attaque doit etre inferieur au points de forces entrees en parametre")
//    {
//        double pointDeSolidite = 10.0;
//        armure a{pointDeSolidite};
//        double pointDeForce = 5;
//        REQUIRE_LT(pointDeForce,a.attaqueMonstre(pointDeForce));
//    }
//
//    SUBCASE("Verification des points de solidite apres absorption de l'armure dans le cas ou la solidite n'atteint pas 0")
//    {
//        double solidite = 16.0;
//        armure armure{solidite};
//        double f = 4.0;
//        armure.absorbe(f);
//        REQUIRE_GT(solidite,armure.getPointSolidite());
//        REQUIRE_EQ(armure.getPointSolidite(),f-(f/2));
//    }
//
//    SUBCASE("Verification des points de solidite apres absorption de l'armure dans le cas ou la solidite atteint 0")
//    {
//        double solidite = 4.0;
//        armure armure{solidite};
//        double f = 16.0;
//        armure.absorbe(f);
//        REQUIRE_GT(solidite,armure.getPointSolidite());
//        REQUIRE_EQ(armure.getPointSolidite(),0.0);
//    }
//}
//
