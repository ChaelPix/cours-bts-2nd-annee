#include <vector>
#include <chrono>
#include <iostream>
#include "MCP4725.h"

// Le constructeur de la classe
MCP4725::MCP4725(BusI2C *bus)
{
    this->bus = bus;
    this->address = MCP4725::defaultAddress;
    this->error = "Pas d\'erreur";
    this->setValVRefVDD();
}

// Les mutateurs ou setters de la classe
void MCP4725::setValVRefVDD(double valVRefVDD)
{
    this->valVRefVDD = valVRefVDD;
}

// Les ascesseurs ou getters de la classe
double MCP4725::getValVRefVDD() const
{
    return this->valVRefVDD;
}


// La méthode init() a appeler en premier apres avoir instancié un objet MCP4728
bool MCP4725::init()
{
    if (bus == nullptr) {
        error = "Adresse du bus I2C non valide";
        return false;
    }

    bus->setSlaveAddr(this->address);
    if (!bus->initBus()) {
        error = bus->getLastError();
        return false;
    }
    
    std::vector<std::uint8_t> donnees;
    donnees.push_back(MCP4725::GeneralCallCommand);
    donnees.push_back(MCP4725::GeneralCallReset);

    if (!bus->i2cSendByte(donnees.data(),donnees.size())) {
        error = bus->getLastError();
        return false;
    }

    return true;
}

// Fixe la tension de sortie du canal actif
bool MCP4725::writeAnalog(double voltage)
{
    if (voltage < 0) {
        error = "La tension de sortie ne peut être inférieure à 0V";
        return false;
    }

    if (voltage > valVRefVDD) {
        error = "La tension de sortie ne peut etre supérieure à la tension d\'alimentation (par ex: 3.3V)";
        return false;
    }

    // calcul de la valeur à écrire dans le DAC (formule issue de la doc)
    std::uint16_t valDAC = static_cast<uint16_t>(
            (voltage * 4095) / (valVRefVDD) );
    
    // Debug
    //std::cout << "valDAC: " << std::hex << (int)valDAC << std::dec << std::endl;
    
    std::vector<std::uint8_t> donnees;
    std::uint8_t octet = 0;
    
    octet = ( MCP4725::FastModeWriteCommand << 4 ) |
            ( static_cast<uint8_t>((valDAC&0x0F00)>>8) );
    donnees.push_back(octet);
    // Debug
    //std::cout << "Octet1: " << std::hex << (int)octet << std::dec << std::endl;
    
    octet = 0;
    octet = static_cast<uint8_t>( valDAC & 0x00FF );
    donnees.push_back(octet);
    // Debug
    //std::cout << "Octet2: " << std::hex << (int)octet << std::dec << std::endl;
    
    // Deuxième méthode pour envoyer des données pour le DAC
    /*
    octet = 0x40;
    donnees.push_back(octet);  // d'apres doc Write DAC register : octet1 -> C2C1C0XXPD1PD0X = 0100 00000 = 0x40
    //std::cout << "Octet1: " << std::hex << (int)octet << std::dec << std::endl;

    octet = 0;
    octet = static_cast<uint8_t>((valDAC & 0x0FF0)>>4); // octet2 -> D11 à D4
    donnees.push_back(octet);
    //std::cout << "Octet2: " << std::hex << (int)octet << std::dec << std::endl;

    octet = 0;
    octet = static_cast<uint8_t>((valDAC & 0x000F) << 4); // octet3 -> D3 à D0 0000
    donnees.push_back(octet);
    //std::cout << "Octet3: " << std::hex << (int)octet << std::dec << std::endl;
    */

    if (!bus->i2cSendByte(donnees.data(),donnees.size())) {
        error = bus->getLastError();
        return false;
    }

    return true;
}

//Retourne le texte descriptif de la dernière erreur
std::string MCP4725::getLastError()
{
    std::string temp = error;
    error = "Pas d`erreur";
    return temp;
}
