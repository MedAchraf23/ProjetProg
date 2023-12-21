#include "armure.h"
#include "doctest.h"

TEST_CASE("La class armure fonctionne correctement") {

    SUBCASE("Le reste des points de force doit etre inferieur au points de forces entrees en parametre") {
        double pointDeSolidite = 10;
        armure a{10};
        double pointDeForce = 5;
        REQUIRE_NE(pointDeForce,a.attaqueMonstre(pointDeForce));
    }
}

