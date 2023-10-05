#pragma once
#include <string>

class TrameAnalyzer
{
private:

	std::string trame;
	std::string date;
	double temp;
	double humidite;
	double humiditeCorrigee;

public:
	TrameAnalyzer(char trame[]);
	std::string getDate();
	double getTemp();
	double getHumidite();
	double gethumiditeCorrigee();
};

