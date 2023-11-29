#include <iostream> 
#include <unistd.h> // Utilisation du délai en microsecondes 
#include <iomanip> // alignement à droite setw(x)
#include "hatGrovePi.h" // classe hatGrovePi

int test()
{
	hatGrovePi hat(1, 0x04); // XXX = adresse de la carte sur le bus i2c
	unsigned short res;
	int resVolt;
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

		resVolt = res * quantum * 1000;
		std::cout << '\r' << std::right << std::setw(10) << "Un = " << res << " Ue = " << resVolt << " mV" << std::flush;

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

int dddmain()
{
	hatGrovePi hat(1, 0x08); // XXX = adresse de la carte sur le bus i2c
	unsigned short res;
	float resVolt;
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

		resVolt = res * quantum * 1000;
		std::cout << '\r' << std::right << std::setw(10) << "Un = " << res << " Ue = " << resVolt << " AmV" << std::flush;

		usleep(50000);
	}

	hat.end();

	return 0;
}

int prog()
{
	hatGrovePi hat(1, 0x08); // XXX = adresse de la carte sur le bus i2c
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
}

//triangle
#include <iostream>
#include <unistd.h>
#include "busi2c.h"
#include "MCP4725.h"
using namespace std;
int dmain(int argc, char** argv)
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
	double valeur = 0.1;
	double y = 0.2;
	int f = 20000;
	double vMax = 0.2;
	double vMin = 0.1;
	double step = 0.01;
	double pauseParStep = f * step * (vMax - vMin) * 10;
	while (true) {
		y = vMax; // Vmax = 3 V
		while (y >= vMin) {
			y -= step;
			if (!cna.writeAnalog(y)) {
				cout << cna.getLastError() << endl;
				bus.closeBus();
				return 0;
			}
			usleep(pauseParStep);
		}
	}
	bus.closeBus();
	cout << "--- Fin programme ---" << endl;
	return 0;
}


//triangle
#include <iostream>
#include <unistd.h>
#include "busi2c.h"
#include "MCP4725.h"
using namespace std;
int maingf(int argc, char** argv)
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
	double valeur = 0.1;
	double y = 0.2;
	double v[] = { 1, 3 }; //On crée le tableau v “valeur” avec la Vmax et Vmin;
	int f = 10000;
	int step = 0; // l’étape qui définit la valeur
	while (true) {
		y = v[step]; // on commence par l’état de Vmin, donc 1V
		if (!cna.writeAnalog(y)) { // teste
			cout << cna.getLastError() << endl;
			bus.closeBus();
			return 0;
		}
		if (step == 0) // si il vaut 0, on le passe à 1 et vice versa
			step = 1;
		else
			step = 0;
		usleep(f); // Fréquence / 2
	}
	bus.closeBus();
	cout << "--- Fin programme ---" << endl;
	return 0;
}

int main()
{
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


int maind()
{

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
	float f[] = { 10000, 5000 }; //
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