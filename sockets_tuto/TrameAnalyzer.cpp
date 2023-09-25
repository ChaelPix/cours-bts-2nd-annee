#include "TrameAnalyzer.h"

TrameAnalyzer::TrameAnalyzer(char ctrame[])
{
	trame = ctrame;

	int start = 0;
	int end = trame.find("T:");
	date = trame.substr(start, end - start); 

	start = trame.find("T:") + 2;
	end = trame.find("°C");
	temp = std::stof(trame.substr(start, end - start));

	start = trame.find("H:") + 2;
	end = trame.find("%");
	humidite = std::stof(trame.substr(start, end - start));

	humiditeCorrigee = humidite + (25 - temp) * -0.15; //coeff du capteur
}


std::string TrameAnalyzer::getDate()
{
	return date;
}

float TrameAnalyzer::getTemp()
{
	return temp;
}

float TrameAnalyzer::getHumidite()
{
	return humidite;
}

float TrameAnalyzer::gethumiditeCorrigee()
{
	return humiditeCorrigee;
}
