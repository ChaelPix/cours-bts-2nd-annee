#include "Personne.h"
#include <iostream>
#include <Windows.h>
//#include "catch2/catch_test_macros.hpp"

//#define CATCH_CONFIG_MAIN  // Ceci indique à Catch de fournir une fonction main()
//#include "catch_amalgamated.hpp"
//
//int add(int a, int b);
//int subtract(int a, int b);
//
//TEST_CASE("Test des fonctions add et subtract", "[math]") {
//    SECTION("Test de la fonction add") {
//        REQUIRE(add(2, 3) == 5);
//        REQUIRE(add(-2, 2) == 0);
//        REQUIRE(add(-2, -3) == -5);
//    }
//
//    SECTION("Test de la fonction subtract") {
//        REQUIRE(subtract(5, 3) == 2);
//        REQUIRE(subtract(2, 2) == 0);
//        REQUIRE(subtract(2, 5) == -3);
//    }
//};
int add(int x, int y)
{
    return x + y;
}

//TEST_CASE("Factorials are computed", "[factorial]") {
//    int z = 1;
//    int r = 5;
//
//    REQUIRE(add(r, z) < 15);
//}


int main() {
    std::string s;

    std::cout << "Entrez votre num\202ro de s\202cu (15 chiffres) [d: pour exemple] \n";
    std::cin >> s;
    if (s == "d")
        s = "103061730041813";

    Personne personne(s);

    if (s.length() != 15 || !personne.verifCleNumSecu())
    {
        std::cout << "Ce n'est pas un bon num\202ro !!! Imposteur !!!!!!!!!!!!!!";
        return 0;
    }
 

    std::cout << "Entrez votre adresse : ";
    std::cin >> s;
    personne.setAdresse(s);

    int x;
    std::cout << "Entrez votre nombre d'enfants : ";
    std::cin >> x;
    personne.setNbe(x);

    std::cout << std::endl << "--------------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << "\t ....:ANALYSE DU FUTUR EN COURS:...." << std::endl;
    Sleep(1500);
    std::cout << "Traduction binaire hexa du futur... ";
    Sleep(500);
    std::cout << "... OK ";
    Sleep(250);
    std::cout << std::endl << "Creation d'une classe abstraite contenant une m\202thode virtuelle... ";
    Sleep(500);
    std::cout << "... OK ";
    Sleep(250);
    std::cout << std::endl << "Interrogation de la base de donn\202es de la NASA... ";
    Sleep(500);
    std::cout << "... OK ";
    Sleep(250);
    std::cout << std::endl << "R\202cup\202ration des donn\202es via un protocole de TCP fiable... ";
    Sleep(500);
    std::cout << "... OK ";
    Sleep(1500);
    std::cout << std::endl << std::endl << "\t ....:ANALYSE DU FUTUR TERMINEE:...." << std::endl << std::endl;

    std::cout << std::endl << personne.toString() << std::endl;



    return 0;
}
