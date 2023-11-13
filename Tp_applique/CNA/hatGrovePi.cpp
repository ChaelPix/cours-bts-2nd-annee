#include "hatGrovePi.h"
#include <iostream>

// constructeur
hatGrovePi::hatGrovePi(unsigned char busNumber, unsigned char addrSTM32HatGrovePi)
{
    this->busNumber = busNumber;
    this->addrSTM32HatGrovePi = addrSTM32HatGrovePi;
    this->errorMsg = "No error !";
    this->fd = -1;
}

// méthode initialisation
bool hatGrovePi::init()
{
    std::string busName {"/dev/i2c-"};
    busName += std::to_string(this->busNumber);

    // Ouverture du bus i2c
    this->fd = open(busName.c_str(), O_RDWR);
    if (this->fd < 0) {
        this->errorMsg = "Error opening i2c bus";
         // message d'erreur à transformer en string : strerror(errno);
        return false;
    }

    // On fixe l'adresse avec qui on veut parler sur le bus i2c : ici par défaut 0x04
    if (ioctl(this->fd, I2C_SLAVE, this->addrSTM32HatGrovePi) < 0) {
        //cout << "Erreur ioctl : " << strerror(errno) << endl;
        this->errorMsg = "Error setting slave address";
        close(this->fd);
        return false;
    }

    return true;
}

// Getters
unsigned char hatGrovePi::getBusNumber() const
{
    return this->busNumber;
}

unsigned char hatGrovePi::getAddrSTM32HatGrovePi() const
{
    return this->addrSTM32HatGrovePi;
}

// Lecture en mode brut (nombre de 0 à 65535) de la conversion par le CAN
bool hatGrovePi::readChannelRaw(unsigned char channel, unsigned short& result)
{
    return readADC(addrRegister::StartAddrRegRaw, channel, result);
}

bool hatGrovePi::readChannelmV(unsigned char channel, unsigned short& result)
{
    return readADC(addrRegister::StartAddrRegmV, channel, result);
}

bool hatGrovePi::readChannelPercent(unsigned char channel, unsigned short& result)
{
    return readADC(addrRegister::StartAddrRegPercent, channel, result);
}

bool hatGrovePi::readAllChannelRaw(std::vector<unsigned short>& results)
{
    return readAllADC(addrRegister::StartAddrRegRaw, results);   
}

bool hatGrovePi::readAllChannelmV(std::vector<unsigned short>& results)
{
    return readAllADC(addrRegister::StartAddrRegmV, results);   
}

bool hatGrovePi::readAllChannelPercent(std::vector<unsigned short>& results)
{
    return readAllADC(addrRegister::StartAddrRegPercent, results);   
}

bool hatGrovePi::readADC(addrRegister readFormat, unsigned char channel, unsigned short& result)
{
    if (channel > this->nbMaxChannelCAN - 1) {
        this->errorMsg = "Channel number mest be between 0 and 7";
        return false;
    }

    int readRegister = static_cast<int>(readFormat) + channel;

    if (write(this->fd, &readRegister, 1) != 1) {
            this->errorMsg = "Error writing on i2c bus";
            return false;
    }

    // Lecture du résulat de la conversion CAN sur 16 bits
    std::vector<unsigned char> buffer;
    buffer.reserve(nbOctetsALire);
    if (read(this->fd, buffer.data(), this->nbOctetsALire) != this->nbOctetsALire) {
        this->errorMsg = "Error reading result on ADC";
        return false;
    }

    result = (buffer[1]<<8) + buffer[0];
    return true;
}

bool hatGrovePi::readAllADC(addrRegister readFormat, std::vector<unsigned short>& results)
{
    unsigned short result;

    for (unsigned char i=0; i<nbMaxChannelCAN; i++) {
        if (!readADC(readFormat, i, result))
            return false;
        else
            results.push_back(result);
    }

    return true;
}

// Fermeture du bus i2c
bool hatGrovePi::end()
{
    if (fd > 0)
        close(this->fd);
    return true;
}

// Recupération de la chaine qui décrit les erreurs
std::string hatGrovePi::getLastError()
{
    std::string temp { this->errorMsg };
    this->errorMsg = "No error !";
    return temp;
}
