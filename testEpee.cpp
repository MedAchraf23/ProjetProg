#include "doctest.h"
#include "epee.h"

TEST_CASE("La class epee fonctionne correctement") {

    SUBCASE("Verifier que l'epee perd en solidite lorsque elle attaque un monstre")
    {
        double pointDeSolidite = 10.0;
        epee epee{pointDeSolidite};
        epee.attaqueEpee();
        REQUIRE_LT(pointDeSolidite,epee.getPointSolidite());
    }
}

