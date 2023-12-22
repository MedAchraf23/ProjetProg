#include "doctest.h"
#include "monstreAveugle.h"


TEST_CASE("La class monstreAveugle fonctionne correctement") {

    SUBCASE("Test deplacement aleatoire du monstre aveugle")
    {
        monstreAveugle mA{10,11,12,20,20};
        double pointDeSolidite = 10.0;
        epee epee{pointDeSolidite};
        epee.attaqueEpee();
        REQUIRE_LT(pointDeSolidite,epee.getPointSolidite());
    }
}
