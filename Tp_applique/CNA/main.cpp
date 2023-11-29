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
int triangle();

int main()
{
	triangle();
	return 0;

	cout << "--- Debut du programme ---" << endl;
	BusI2C bus("/dev/i2c-1");
	MCP4725 cna(&bus);
	if (!cna.init()) {
		cout << cna.getLastError() << endl;
		bus.closeBus();
		return 0;
	}
	usleep(100);
	double y = 0;

	double v[] = { 1, 3 }; //On crée le tableau v “valeur” avec la Vmax et Vmin;
	float traitementDonnes = 500;
	float f[] = { 10000, 5000}; //
	int step = 0; // l’étape qui définit la valeur

	while (true) {
		y = v[step]; // on commence par l’état de Vmin, donc 1V
		if (!cna.writeAnalog(y)) { // teste
			cout << cna.getLastError() << endl;
			bus.closeBus();
			return 0;
		}
		
		usleep(f[step] - traitementDonnes); // Fréquence

		if (step == 0) // si il vaut 0, on le passe à 1 et vice versa
			step = 1;
		else
			step = 0;
	}
}
int triangle()
{
	cout << "--- Debut du programme steferer ---" << endl;
	BusI2C bus("/dev/i2c-1");
	MCP4725 cna(&bus);
	if (!cna.init()) {
		cout << cna.getLastError() << endl;
		bus.closeBus();
		return 0;
	}
	usleep(100);

	double y = 0;
	int f = 20000;
	double vMax = 2;
	double vMin = 1;
	int step = 0;
	int pas = 1;
	int nbPas = 40;
	double pauseParStep = f / nbPas;

	float values[20];

	for (int i = 0; i < 20; i++)
	{
		values[i] = vMin + (((vMax - vMin) / (nbPas / 2)) * i);
		std::cout << values[i];
	}

	while (true) {
		if (step >= nbPas / 2)
		{
			y = values[nbPas / 2 - (step - nbPas / 2)];
		}
		else
		{
			y = values[nbPas];
		}


		step += pas;
		if (step >= nbPas)
		{
			step = 0;
		}

		if (!cna.writeAnalog(y)) {
			cout << cna.getLastError() << endl;
			bus.closeBus();
			return 0;
		}
		usleep(pauseParStep);
	}
	bus.closeBus();
	cout << "--- Fin programme ---" << endl;
	return 0;
}
//int main(int argc, char** argv)
//{
//	cout << "--- Debut prog" << endl;
//	BusI2C bus("/dev/i2c-1");
//	MCP4725 cna(&bus);
//	if (!cna.init()) {
//		cout << cna.getLastError() << endl;
//		bus.closeBus();
//		return 0;
//	}
//	usleep(100);
//	hatGrovePi h;
//	if (!h.init()) {
//		cout << h.getLastError() << endl;
//		return 0;
//	}
//	unsigned short val; // variable pour la lecture du CAN : attention valeur en mV
//	cna.setValVRefVDD(3.3);
//	double xn, xn1, xn2, yn, yn1, yn2;
//	xn = xn1 = xn2 = yn = yn1 = yn2 = 0.0;
//
//	const int sleepTemps = 200;
//
//	double a0 = 1;
//	double a1 = -1.618;
//	double a2 = 1;
//	double b1 = 1.4;
//	double b2 = -0.878;
//
//	while (true) {
//
//		h.readChannelmV(0, val);
//
//		yn2 = yn1;
//		yn1 = yn;
//		xn2 = xn1;
//		xn1 = xn;
//		xn = val / 1000.0;
//
//		yn = (a0 * xn + a1 * xn1 + a2 * xn2 + b1 * yn1 + b2 * yn2) / 100;
//		yn += 1;
//		std::cout << yn << std::endl;
//		
//
//		if (!cna.writeAnalog(yn)) {
//				cout << cna.getLastError() << endl;
//				bus.closeBus();
//				return 0;
//		}
//
//		usleep(sleepTemps);
//	}
//
//	bus.closeBus();
//	h.end();
//	cout << "--- Fin prog" << endl;
//	return 0;
//}