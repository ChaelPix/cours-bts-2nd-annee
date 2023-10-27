// Personne.h

#ifndef _PERSONNE_
#define _PERSONNE_

#include <string>


class Personne {
private:
    int adn = 0;
    int age = 0;
    int nbe = 0;
    std::string adresse = "";
    std::string numSecu = "";
    

public:
    enum class Genre { HOMME, FEMME, INCONNU };

private:
    Genre genre;

public:
    Personne();
    Personne(std::string numSecu);
    std::string getAdresse();
    void setAdresse(std::string adresse);
    int getNbe();
    void setNbe(int nbe);
    void naissanceEnfant();
    std::string toString();
    Genre getGenre();

private:
    void evalAttributs();
    bool verifCleNumSecu();
};

#endif
