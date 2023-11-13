// Fichier de déclaration de la classe hatGrovePi
// O. Dartois, Sept 2020

#ifndef _hatGrovePi_h_
#define _hatGrovePi_h_

// Include necessaire à cette classe
#include <fcntl.h>              /* open */
#include <unistd.h>             /* read, write, close */
#include <string.h>             /* strerr */
#include <sys/ioctl.h>          /* ioctl */
#include <linux/i2c-dev.h>      /* gestion du bus i2c */

#include <vector>
#include <string>

class hatGrovePi
{
    private:
        const unsigned char nbMaxChannelCAN { 8 };
        const unsigned char nbOctetsALire { 2 };
        unsigned char busNumber;
        unsigned char addrSTM32HatGrovePi; 
        int fd;
        std::string errorMsg;

        enum class addrRegister { StartAddrRegRaw = 0x10, StartAddrRegmV = 0x20, StartAddrRegPercent = 0x30 };

    public:
        hatGrovePi(unsigned char busNumber = 1, unsigned char addrSTM32HatGrovePi = 0x04);
        bool init();
        unsigned char getBusNumber() const;
        unsigned char getAddrSTM32HatGrovePi() const;
        bool readChannelRaw(unsigned char channel, unsigned short& result);
        bool readChannelmV(unsigned char channel, unsigned short& result);
        bool readChannelPercent(unsigned char channel, unsigned short& result);
        bool readAllChannelRaw(std::vector<unsigned short>& results);
        bool readAllChannelmV(std::vector<unsigned short>& results);
        bool readAllChannelPercent(std::vector<unsigned short>& results);
        bool end();
        std::string getLastError();

    private:
        bool readADC(addrRegister readFormat, unsigned char channel, unsigned short& result);
        bool readAllADC(addrRegister readFormat, std::vector<unsigned short>& results);
};

#endif
