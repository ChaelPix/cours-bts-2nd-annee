#include "SuperPersonne.h"


SuperPersonne::SuperPersonne() : Personne()
{

}

std::string SuperPersonne::toString()
{
    std::string s;
    s = "Super Personne : " + Personne::getAdresse();

    return s;
}