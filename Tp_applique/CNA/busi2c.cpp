// Implémentation Classe I2C
// O.Dartois, le 03/10/12

#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#include "busi2c.h"

BusI2C::BusI2C(std::string devName, unsigned char slaveAddr)
{
    mdevName = devName;
    mslaveAddr = slaveAddr;
    merror = "";
}

std::string BusI2C::getDeviceName() const
{
    return mdevName;
}

void BusI2C::setDeviceName(std::string devName)
{
    mdevName = devName;
}

void BusI2C::setSlaveAddr(unsigned char slaveAddr)
{
    mslaveAddr = slaveAddr;
}

unsigned char BusI2C::getSlaveAddr()
{
    return mslaveAddr;
}

bool BusI2C::initBus()
{
    if (mdevName == "") {
        merror = "Pas de nom de peripherique pour le bus I2C";
        return false;
    }
    
    if (mslaveAddr == 0) {
        merror = "Adresse esclave ne peut être nulle";
        return false;
    }

    idDeviceDescriptor = open(mdevName.c_str(), O_RDWR);
    if (idDeviceDescriptor == -1) {
        merror = "Erreur ouverture du peripherique";
        return false;
    }

    if ( ioctl(idDeviceDescriptor, I2C_SLAVE, mslaveAddr) < 0 ) {
        merror = "Erreur sur operation IOCTL";
        return false;
    }

    return true;
}

void BusI2C::closeBus()
{
    if (idDeviceDescriptor >= 0)
        close(idDeviceDescriptor);

}

std::string BusI2C::getLastError()
{
    std::string temp = merror;
    merror = "Pas d\'erreur...";
    return temp;
}

bool BusI2C::i2cSendByte(unsigned char *data, int len)
{
    int result = write(idDeviceDescriptor, data, len);
    if (result == -1) {
        merror = "Erreur ecriture sur le bus I2C";
        return false;
    }

    return true;
}

bool BusI2C::i2cReadByte(unsigned char *data, int len)
{
    int result = read(idDeviceDescriptor, data, len);
    if (result == -1) {
        merror = "Erreur lecture sur le bus I2C";
        return false;
    }

    return true;
}
