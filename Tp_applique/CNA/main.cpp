#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include "busi2c.h"
#include "MCP4725.h"

#include "hatGrovePi.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "--- Debut prog" << endl;
	BusI2C bus("/dev/i2c-1");
	MCP4725 cna(&bus);
	if (!cna.init()) {
		cout << cna.getLastError() << endl;
		bus.closeBus();
		return 0;
	}
	usleep(100);
	hatGrovePi h;
	if (!h.init()) {
		cout << h.getLastError() << endl;
		return 0;
	}
	unsigned short val; // variable pour la lecture du CAN : attention valeur en mV
	cna.setValVRefVDD(3.3);
	double xn, xn1, xn2, yn, yn1, yn2;
	xn = xn1 = xn2 = yn = yn1 = yn2 = 0.0;

	const int sleepTemps = 200;

	double a0 = 1;
	double a1 = -1.618;
	double a2 = 1;
	double b1 = 1.4;
	double b2 = -0.878;

	while (true) {

		h.readChannelmV(0, val);

		yn2 = yn1;
		yn1 = yn;
		xn2 = xn1;
		xn1 = xn;
		xn = val / 1000.0;

		yn = (a0 * xn + a1 * xn1 + a2 * xn2 + b1 * yn1 + b2 * yn2) / 100;
		yn += 1;
		std::cout << yn << std::endl;
		

		if (!cna.writeAnalog(yn)) {
				cout << cna.getLastError() << endl;
				bus.closeBus();
				return 0;
		}

		usleep(sleepTemps);
	}

	bus.closeBus();
	h.end();
	cout << "--- Fin prog" << endl;
	return 0;
}