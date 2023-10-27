#include "TrameAnalyzer.h"

TrameAnalyzer::TrameAnalyzer(char ctrame[])
{
	trame = ctrame;

	int start = 0;
	int end = trame.find("T:");
	date = trame.substr(start, end - start); 

	start = trame.find("T:") + 2;
	end = trame.find("°C");
	temp = std::stod(trame.substr(start, end - start));

	start = trame.find("H:") + 2;
	end = trame.find("%");
	humidite = std::stod(trame.substr(start, end - start));

	humiditeCorrigee = humidite + (25 - temp) * -0.15; //coeff du capteur
}


std::string TrameAnalyzer::getDate()
{
	return date;
}

double TrameAnalyzer::getTemp()
{
	return temp;
}

double TrameAnalyzer::getHumidite()
{
	return humidite;
}

double TrameAnalyzer::gethumiditeCorrigee()
{
	return humiditeCorrigee;
}
