#pragma once
#include <string>

class TrameAnalyzer
{

private:

	std::string trame;
	std::string date;
	float temp;
	float humidite;
	float humiditeCorrigee;

public:

	TrameAnalyzer(char trame[]);

	std::string getDate();
	float getTemp();
	float getHumidite();
	float gethumiditeCorrigee();
};

