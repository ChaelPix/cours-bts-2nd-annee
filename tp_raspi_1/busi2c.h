/// Fichier d'entête Classe I2C
// O.Dartois, le 03/10/12
// Modif le 29/05/17
 
#ifndef BUSI2C_H
#define BUSI2C_H

#include <string>


class BusI2C
{

public:
    BusI2C(std::string devName, unsigned char slaveAddr = 0);
	void setDeviceName(std::string devName);
	std::string getDeviceName() const;
    void setSlaveAddr(unsigned char slaveAddr);
    unsigned char getSlaveAddr();
	bool initBus();
	void closeBus();
    bool i2cSendByte(unsigned char* data, int len);
    bool i2cReadByte(unsigned char* data, int len);
	std::string getLastError();

private:
	std::string mdevName;
	std::string merror;
    int idDeviceDescriptor;
    unsigned char mslaveAddr;

};

#endif // BUSI2C_H

