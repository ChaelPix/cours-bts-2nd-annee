/**
\mainpage Classe de pilotage du CNA 12bits MPC4725 sur bus I2C pour GNU/Linux (BBB, RPi, etc...)
\author Olivier DARTOIS
\date Sept 2021

Cette classe permet d'exploiter un convertisseur numérique analogique 12 bits sur bus I2C du constructeur MicroChip

\file MCP4725.h
Déclaration de la classe MCP4725
\class MCP4725
\brief Cette classe permet d'exploiter un CNA 12bits MPC4725 sur bus I2

La plupart des méthodes renvoient un booléen qui
indique si l'action demandée a réussi ou échoué. Il est donc de la responsabilité de
l'utilisateur de cette classe de tester le booléen de retour.
Pour obtenir une description de l'erreur, il faut faire appel à la méthode getLastError()
qui renvoie une chaine (objet string).

Remarque: cette classe n'implémente pas toutes les commandes que comprend le MCP4725 mais
seulement celles qui sont nécessaires pour le fonctionnement minimum (changer la valeur de
la tension en sortie).

*/

#ifndef _MCP4725_H_
#define _MCP4725_H_

#include <cstdint>
#include <string>

#include "busi2c.h"

class MCP4725
{
public:
    const static std::uint8_t defaultAddress    = 0x60; ///< Adresse par défaut du CNA MCP4725 sur le bus i2c

    const std::uint8_t GeneralCallCommand	   	= 0x00; ///< Valeur qui doit être envoyée avant toute commande générale
    const std::uint8_t GeneralCallReset		    = 0x06; ///< Commande de remise à zéro du composant (Reset)
    const std::uint8_t GeneralCallWakeUp		= 0x09; ///< Commande de réveil du composant (aprés une mise en veille)
    const std::uint8_t FastModeWriteCommand	    = 0x00; ///< Commande d'écriture des registres de sorties du CNA sans mise à jour de l'EEPROM (C2=0, C1=0, PD1=0, PD2=0)

    /**
        * \brief Constructeur de la classe MCP4728
        *
        * Ce constructeur initialise les attributs privé de la classe.
        *
        * \param[in] bus un pointeur de type BusI2C qui doit être instancié auparavant (voir la classe BusI2C)
        */
    MCP4725(BusI2C* bus);

    /**
        * \brief Méthode init
        *
        * Cette méthode doit être appellé en premier aprés avoir instancié un objet de la classe MCP4728.
        *
        * \return booléen qui indique si la méthode init() a échoué (false) ou réussi (true)
        */
    bool init();


    /**
        * \brief Méthode setValVRefVDD
        *
        * Cette méthode permet de fixer la valeur de la tension VDD (tension d'alimentation du CNA)
        * lorsque celle-ci est choisie comme tension de référence.
        * Par défaut celle-ci sera fixé à 3,3V, tension d'alimentation du RaspberryPi 
        *
        * \param[in] valVRefVDD Valeur de la tension d'alimentation en flottant exprimée en volts.
        */
    void setValVRefVDD(double valVRefVDD = 3.3);

    /**
        * \brief Méthode getValVRefVDD
        *
        * Cette méthode permet de lire la valeur de la tension VDD (tension d'alimentation du CNA)
        * lorsque celle-ci est choisie comme tension de référence. 
        *
        * \return Valeur de la tension d'alimentation en flottant exprimée en volts.
        */
    double getValVRefVDD() const;
    
    /**
        * \brief Méthode writeAnalog
        *
        * Cette méthode permet de fixer la tension de sortie en volts du canal actif
        *
        * \return booléen qui indique si la méthode init() a échoué (false) ou réussi (true)
        */
    bool writeAnalog(double voltage);

    /**
        * \brief getLastError
        *
        * Cette méthode renvoie le dernier message d'erreur sous forme de chaine de caractères (type string). Il faut
        * l'appeler aprés chaque appel d'une méthode qui renvoie un booléen faux.
        *
        * \return une chaine de caractère (string) qui contient le message d'erreur
        */
    std::string getLastError();

private:

    /// Pointeur contenant l'adresse du bus I2C sur lequel on va dialoguer (pointeur donc aggrégation)
    BusI2C* bus;

    /// Adresse du MCP4725 sur le bus i2c
    std::uint8_t address;
    
    ///Valeur de la tension VDD si c'est celle-ci qui est sélectionnée comme tension de référence du CNA
    double valVRefVDD;

    /// Cette chaine contient le dernier message d'erreur
    std::string error;

};

#endif
