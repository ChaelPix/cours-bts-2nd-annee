#include <iostream> 
#include <unistd.h> // Utilisation du délai en microsecondes 
#include <iomanip> // alignement à droite setw(x)
#include "hatGrovePi.h" // classe hatGrovePi

#include <pigpio.h>
#include <string>
#include <bitset>
#include <cmath>

std::string toBinaryWithSeparation(unsigned short val) {
	std::bitset<16> b(val);
	std::string binaryStr = b.to_string();

	std::string result = "";
	int count = 0;
	for (int i = binaryStr.length() - 1; i >= 0; --i) {
		result = binaryStr[i] + result;
		count++;
		if (count % 4 == 0 && i != 0) {
			result = " " + result;
		}
	}
	return result;
}

int r()
{
	hatGrovePi hat(1, 0x08);
	unsigned short res; // Un
	int resVolt;

	int k = 5;
	float m = 0;

	float quantum = 0.0008049;

	if (!hat.init()) {
		std::cout << hat.getLastError() << std::endl;
		return 0;
	}
	while (1)
	{
		if (!hat.readChannelRaw(0, res))
		{
			std::cout << hat.getLastError() << std::endl;
			hat.end();
			return 0;
		}

		m = (m * (k - 1) + res) / k;
		std::cout << '\r' << std::right << std::setw(5) << "Un - Decimal : " << m << " Binaire : " << toBinaryWithSeparation(static_cast<unsigned short>(m)) << std::flush;
		usleep(50000);
	}

	hat.end();
	return 0;
}

int truc()
{
	hatGrovePi hat(1, 0x08);
	unsigned short res; // Un
	int resVolt;

	int k = 5;
	float m = 0;

	float quantum = 0.0008049;
	if (!hat.init()) {
		std::cout << hat.getLastError() << std::endl;
		return 0;
	}
	while (1)
	{
		if (!hat.readChannelRaw(0, res))
		{
			std::cout << hat.getLastError() << std::endl;
			hat.end();
			return 0;
		}

		m = (m * (k - 1) + res) / k;
		std::cout << '\r' << std::right << std::setw(5) << "Un - Decimal : " << m << " Binaire : " << toBinaryWithSeparation(static_cast<unsigned short>(m)) << std::flush;
		usleep(50000);
	}

	hat.end();
	return 0;
}

int main()
{
	hatGrovePi hat(1, 0x08); // XXX = adresse de la carte sur le bus i2c
	unsigned short res; //Un

	float quantum = 0.0008049;
	int lux;

	if (!hat.init()) {
		std::cout << hat.getLastError() << std::endl;
		return 0;
	}

	while (1)
	{
		if (!hat.readChannelRaw(0, res))
		{
			std::cout << hat.getLastError() << std::endl;
			hat.end();
			return 0;
		}

		lux = exp(log(res / (6.94 * 1e3)) / -0.416);

		std::cout << '\r' << std::right << std::setw(10) << "Un = " << res << "Lux = " << lux << std::flush;

		usleep(50000);
	}

	hat.end();
	return 0;
}

int s()
{
	int k = 3;
	float m = 0;
	int un = 10;
	

	for (int i = 0; i < 21; i++)
	{
		m = (m * (k - 1) + un) / k;

		std::cout << i << " : " << m << std::endl;

		usleep(50000);
	}

	std::cout << std::endl;
	return 0;
}


int ss()
{
	hatGrovePi hat(1, 0x04); // XXX = adresse de la carte sur le bus i2c
	unsigned short res; // Un
	int resVolt;

	int k = 100;
	float m = 0;

	float quantum = 0.0008049;
	if (!hat.init()) {
		std::cout << hat.getLastError() << std::endl;
		return 0;
	}
	while (1)
	{
		if (!hat.readChannelRaw(0, res))
		{
			std::cout << hat.getLastError() << std::endl;
			hat.end();
			return 0;
		}

		m = (m * (k - 1) + res) / k;
		std::cout << '\r' << std::right << std::setw(5) << "Un = " << m << std::flush;

		usleep(50000);
	}

	hat.end();
	return 0;
}
