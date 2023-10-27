// Personne.h

#ifndef _PERSONNE_
#define _PERSONNE_

#include <string>

enum GENRE {
    HOMME,
    FEMME,
    INCONNU
};

class Personne {
private:
    int adn = 0;
    int age = 0;
    int nbe = 0;
    std::string adresse = "";
    std::string numSecu = "";
    GENRE genre = GENRE::INCONNU;

    void evalAttributs();
    bool verifCleNumSecu();

public:
    Personne();
    Personne(std::string numSecu);
    std::string getAdresse();
    void setAdresse(std::string adresse);
    int getNbe();
    void setNbe(int nbe);
    void naissanceEnfant();
    std::string toString();
};

#endif
