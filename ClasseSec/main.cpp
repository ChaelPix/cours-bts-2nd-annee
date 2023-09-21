#include "Personne.h"
#include <iostream>
#include <Windows.h>
//#include "catch_amalgamated.hpp"

#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

TEST_CASE("Tests pour la classe Personne", "[Personne]") {


    //SECTION("V\202rification du num\202ro de s\202curit\202 sociale") {
    //    REQUIRE(personne.verifCleNumSecu() == true);

    //    Personne personneInvalide("123456789012345");
    //    REQUIRE(personneInvalide.verifCleNumSecu() == false);
    //}

    SECTION("Test des exceptions pour le num\202ro de s\202curit\202 sociale invalide") {
        REQUIRE_THROWS_AS(Personne("12345"), const char*); // Num\202ro trop court
        REQUIRE_THROWS_AS(Personne("12345678901234567890"), const char*); // Num\202ro trop long
        REQUIRE_THROWS_WITH(Personne("12345"), "Taille du numero de secu incorrect");
    }

    SECTION("Test des exceptions pour la cl\202 de s\202curit\202 sociale invalide") {
        REQUIRE_THROWS_AS(Personne("103061730041810"), const char*);
        REQUIRE_THROWS_WITH(Personne("123456789012045"), "Cle secu incorrecte");
    }

    SECTION("Test de la cr\202ation valide d'une personne") {
        REQUIRE_NOTHROW(Personne("103061730041813"));
    }

    Personne personne = Personne("103061730041813");
    SECTION("Test de l'adresse") {
        REQUIRE(personne.getAdresse() == ""); 

        personne.setAdresse("123 rue de Turgot");
        REQUIRE(personne.getAdresse() == "123 rue de Turgot");
    }

    SECTION("Test du nombre d'enfants") {
        REQUIRE(personne.getNbe() == 0);

        personne.setNbe(2);
        REQUIRE(personne.getNbe() == 2);

        personne.naissanceEnfant();
        REQUIRE(personne.getNbe() == 3);
    }

    SECTION("Test du genre bas\202 sur le num\202ro de s\202curit\202 sociale") {
        Personne homme("103061730041813");
        REQUIRE(homme.getGenre() == Personne::Genre::HOMME);

        //Personne femme("292053300200308");
        //REQUIRE(femme.getGenre() == Personne::Genre::FEMME);

        //Personne inconnu("390010750010011");
        //REQUIRE(inconnu.getGenre() == Personne::Genre::INCONNU);
    }
}

int main(int argc, char* argv[]) {

    Catch::Session().run(argc, argv);

    std::string s;

    std::cout << "Entrez votre num\202ro de s\202cu (15 chiffres) [d: pour exemple] \n";
    std::cin >> s;
    if (s == "d")
        s = "103061730041813";


    Personne* personnePtr = nullptr;

    try {
        personnePtr = new Personne(s);
    }
    catch (const char* e)
    {
        std::cout << e << " . Imposteur !!!!!!!!!!!!!!";
        return 0;
    }

    std::cout << "Entrez votre adresse : ";
    std::cin >> s;
    personnePtr->setAdresse(s);

    int x;
    std::cout << "Entrez votre nombre d'enfants : ";
    std::cin >> x;
    personnePtr->setNbe(x);

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

    std::cout << std::endl << personnePtr->toString() << std::endl;

    return 0;
}
