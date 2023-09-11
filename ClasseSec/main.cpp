// main.cpp

#include "Personne.h"
#include <iostream>
#include <Windows.h>

int main() {

    std::string s;

    std::cout << "Entrez votre num\202ro de s\202cu (15 chiffres) [d: pour exemple] \n";
    std::cin >> s;
    if (s == "d")
        s = "103061730041813";

    Personne personne(s);

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
    std::cout << std::endl << std::endl << "\t ....:ANALYSE DU FUTUR TERMINE:...." << std::endl << std::endl;

    if (personne.verifCleNumSecu()) {
        std::cout << std::endl << "Num\202ro de s\202curit\202 sociale valide." << std::endl;
    }
    else {
        std::cout << std::endl << "Num\202ro de s\202curit\202 sociale invalide." << std::endl;
    }

    std::cout << std::endl << personne.toString() << std::endl;



    return 0;
}
