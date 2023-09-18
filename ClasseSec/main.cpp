#include "Personne.h"
#include <iostream>
#include <Windows.h>
//#include "catch_amalgamated.hpp"

#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

int add(int a, int b);
int subtract(int a, int b);

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

TEST_CASE("add are computed", "[add]")
{
    REQUIRE(add(1, 0) == 5);
    REQUIRE(add(2, 0) == 2);
    REQUIRE(add(1, 2) == 3);
    REQUIRE(add(10, 5) == 15);
}

TEST_CASE("subtract are computed", "[subtract]")
{
    REQUIRE(subtract(1, 0) == 1);
    REQUIRE(subtract(2, 1) == 1);
    REQUIRE(subtract(3, 2) == 1);
    REQUIRE(subtract(10, 5) == 5);
}

TEST_CASE("Test de la classe Personne", "[Personne]") {
    Personne personne("103061730041813");
    
    SECTION("Vérification du numéro de sécurité sociale") {
        REQUIRE(personne.verifCleNumSecu() == true);
    }

    SECTION("Test de l'adresse") {
        personne.setAdresse("123 rue de la Paix");
        REQUIRE(personne.getAdresse() != "");
    }

    // Ajoutez d'autres sections pour tester d'autres fonctionnalités de votre classe.
}
int main(int argc, char* argv[]) {



    //std::string s;

    //std::cout << "Entrez votre num\202ro de s\202cu (15 chiffres) [d: pour exemple] \n";
    //std::cin >> s;
    //if (s == "d")
    //    s = "103061730041813";

    //Personne personne(s);

    //if (s.length() != 15 || !personne.verifCleNumSecu())
    //{
    //    std::cout << "Ce n'est pas un bon num\202ro !!! Imposteur !!!!!!!!!!!!!!";
    //    return 0;
    //}




    //std::cout << "Entrez votre adresse : ";
    //std::cin >> s;
    //personne.setAdresse(s);

    //int x;
    //std::cout << "Entrez votre nombre d'enfants : ";
    //std::cin >> x;
    //personne.setNbe(x);

    //std::cout << std::endl << "--------------------------------------------------------------------------------------" << std::endl;
    //std::cout << std::endl << "\t ....:ANALYSE DU FUTUR EN COURS:...." << std::endl;
    //Sleep(1500);
    //std::cout << "Traduction binaire hexa du futur... ";
    //Sleep(500);
    //std::cout << "... OK ";
    //Sleep(250);
    //std::cout << std::endl << "Creation d'une classe abstraite contenant une m\202thode virtuelle... ";
    //Sleep(500);
    //std::cout << "... OK ";
    //Sleep(250);
    //std::cout << std::endl << "Interrogation de la base de donn\202es de la NASA... ";
    //Sleep(500);
    //std::cout << "... OK ";
    //Sleep(250);
    //std::cout << std::endl << "R\202cup\202ration des donn\202es via un protocole de TCP fiable... ";
    //Sleep(500);
    //std::cout << "... OK ";
    //Sleep(1500);
    //std::cout << std::endl << std::endl << "\t ....:ANALYSE DU FUTUR TERMINEE:...." << std::endl << std::endl;

    //std::cout << std::endl << personne.toString() << std::endl;

    Catch::Session().run(argc, argv);

    return 0;
}
