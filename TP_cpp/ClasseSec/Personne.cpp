// Personne.cpp

#include "Personne.h"
#include <sstream>

Personne::Personne() : adn(0), age(0), nbe(0), adresse("N/A"), numSecu(""), genre(Genre::INCONNU) {}

Personne::Personne(std::string numSecu) : Personne() {
    this->numSecu = numSecu;

    if (numSecu.length() != 15)
        throw("Taille du numero de secu incorrect");

    if (!verifCleNumSecu())
        throw("Cle secu incorrecte");

    evalAttributs();
}

std::string Personne::getAdresse() {
    return adresse;
}

void Personne::setAdresse(std::string adresse) {
    this->adresse = adresse;
}

int Personne::getNbe() {
    return nbe;
}

void Personne::setNbe(int nbe) {
    this->nbe = nbe;
}

void Personne::evalAttributs() {

    if (numSecu.length() != 15) {      
        return;
    }

    char genderChar = numSecu.at(0);
    if (genderChar == '1') {
        genre = Genre::HOMME;
    }
    else if (genderChar == '2') {
        genre = Genre::FEMME;
    }
    else {
        genre = Genre::INCONNU;
    }

    adn = stoi(numSecu.substr(1, 2));
    if (adn <= 24) { 
        adn += 2000;
    }
    else {
        adn += 1900;
    }

    age = 2023 - adn;
}


bool Personne::verifCleNumSecu()
{
    std::string numSecuSansCle = this->numSecu.substr(0, 13);
    int cleCalc = 0;

    for (int i = 0; i < numSecuSansCle.length(); i++)
        cleCalc = (cleCalc * 10 + (int)numSecuSansCle[i] - '0') % 97;
    cleCalc = 97 - cleCalc;

    int cle = stoi(this->numSecu.substr(13, 2));

    return (cleCalc == cle);
}

void Personne::naissanceEnfant() {
    nbe++;
}

std::string Personne::toString() {
    std::ostringstream oss;

    oss << "Ann\202e de naissance: " << adn << "\n"
        << "Age: " << age << "\n"
        << "Nombre d'enfants: " << nbe << "\n"
        << "Adresse: " << adresse << "\n"
        << "Num\202ro de s\202curit\202 sociale: " << numSecu << "\n"
        << "Genre: ";

    switch (genre) {
    case Genre::HOMME: oss << "HOMME"; break;
    case Genre::FEMME: oss << "FEMME"; break;
    default: oss << "INCONNU"; break;
    }
    return oss.str();
}

Personne::Genre Personne::getGenre()
{
    return genre;
}