#include "doctest.h"
#include "monstreVoyant.h"
#include "aventurier.h"
#include "armure.h"
#include "epee.h"


TEST_CASE("la class monstreVoyant fonctionne correctement")
{


    SUBCASE("Construction d'un monstre voyant")
    {
        armure  bouclier{120};
        epee excalibur{120};
        aventurier indianaJones{100, 100, excalibur, bouclier};
        monstreVoyant   monstreV{140,100,120,15,20};
        REQUIRE_EQ(monstreV.pointsVie(),140);
    }


}
