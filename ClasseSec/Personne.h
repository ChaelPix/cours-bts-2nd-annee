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
    int adn;
    int age;
    int nbe;
    std::string adresse;
    std::string numSecu;
    GENRE genre;

public:
    Personne();
    Personne(std::string numSecu);
    std::string getAdresse();
    void setAdresse(std::string adresse);
    int getNbe();
    void setNbe(int nbe);
    void evalAttributs();
    bool verifCleNumSecu();
    void naissanceEnfant();
    std::string toString();
};

#endif
