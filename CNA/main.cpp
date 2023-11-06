#include <iostream>
#include <unistd.h>
#include <cmath>
#include <vector>
#include "busi2c.h"
#include "MCP4725.h"
using namespace std;

std::vector<double> CalculSignalSinus(){
	 double amplitude = 1.5;
	 double decalage = 1.65;
	 double frequence = 50.0;
	 double omega = 2.0 * M_PI * frequence;
	 int echantillonsParPeriode = 20;
	 double tauxEchantillonnage = echantillonsParPeriode * frequence;
	 double dt = 1.0 / tauxEchantillonnage;

	std::vector<double> valeursSinus(echantillonsParPeriode);

	for (int i = 0; i < echantillonsParPeriode; ++i) {
		double t = i * dt;
		valeursSinus[i] = decalage + amplitude * sin(omega * t);
	}

	for (int i = 0; i < echantillonsParPeriode; ++i) {
		std::cout << "valeursSinus[" << i << "] = " << valeursSinus[i] << std::endl;
	}

	return valeursSinus;
}

int main(int argc, char** argv)
{
	std::cout << "--- Debut du programme steferer ---" << endl;
	BusI2C bus("/dev/i2c-1");
	MCP4725 cna(&bus);
	if (!cna.init()) {
		std::cout << cna.getLastError() << endl;
		bus.closeBus();
		return 0;
	}

	usleep(100);
	double valeur = 0.1;
	double y = 0.3;

	int f = 20000;
	double vMax = 0.3;
	double vMin = 0.1;

	double step = 0.01 ;
	double pauseParStep = f * step * (vMax - vMin) * 10;

	std::vector<double> valeurSignal = CalculSignalSinus();
	int i = 0;


	while (true) {
		y = valeurSignal[i] / 10;

		i++;
		if (i >= valeurSignal.size())
			i = 0;

		if (!cna.writeAnalog(y)) {
			std::cout << cna.getLastError() << endl;
			bus.closeBus();
			return 0;
		}
		usleep(f / valeurSignal.size());
	}

	bus.closeBus();
	std::cout << "--- Fin programme ---" << endl;
	return 0;
}

