//#include "doctest.h"
//#include "monstreVoyant.h"
//#include "aventurier.h"
//#include "armure.h"
//#include "epee.h"
//
//
//TEST_CASE("la class monstreVoyant fonctionne correctement")
//{
//
//    monstreVoyant monstreV {100,120,140,30,20};
//    SUBCASE("Construction d'un monstre voyant")
//    {
//        REQUIRE_EQ(monstreV.pointsVie(),100);
//        REQUIRE_EQ(monstreV.pointsForce(),120);
//        REQUIRE_EQ(monstreV.habilete(),140);
//        REQUIRE_EQ(monstreV.x(),30);
//        REQUIRE_EQ(monstreV.y(),20);
//    }
//    armure  bouclier{120};
//    epee excalibur{120};
//    aventurier indianaJones{100, 100, excalibur, bouclier};
//
//    SUBCASE("Test des deplacement vers aventurier a moins de 8 cases : aventurier a sa gauche")
//    {
//
//        monstreV.seDeplace(24,20);
//        REQUIRE_EQ(monstreV.x(),29);
//        REQUIRE_EQ(monstreV.y(),20);
//    }
//
//    SUBCASE("Test deplacement vers aventurier : aventurier a sa droite")
//    {
//       monstreV.seDeplace(34,20);
//       REQUIRE_EQ(monstreV.x(),31);
//       REQUIRE_EQ(monstreV.y(),20);
//    }
//
//    SUBCASE("Test deplacement vers aventurier : aventurier en haut")
//    {
//        monstreV.seDeplace(30,14);
//        REQUIRE_EQ(monstreV.x(),30);
//        REQUIRE_EQ(monstreV.y(),19);
//
//    }
//
//    SUBCASE("Test deplacement vers aventurier : aventurier en bas")
//    {
//        monstreV.seDeplace(30,24);
//        REQUIRE_EQ(monstreV.x(),30);
//        REQUIRE_EQ(monstreV.y(),21);
//    }
//
//    SUBCASE("Test pas de déplacement car aventurier a + de 8 cases")
//    {
//        monstreV.seDeplace(40,20);
//        REQUIRE_EQ(monstreV.x(),30);
//        REQUIRE_EQ(monstreV.y(),20);
//    }
//
//
//}
//
