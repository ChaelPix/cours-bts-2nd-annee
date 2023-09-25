#include <iostream>
#include <Windows.h>

#include "NIDAQmx.h"

#include "EsMelangeur.h"

#pragma region Questions
/*
Turn on a led
*/
int Q2_2()
{
	TaskHandle valve2Handle;
	int32 error;
	// 1 : Create Task
	std::cout << "...: Create Task :..." << std::endl;
	if (DAQmxCreateTask("", &valve2Handle) < 0)
	{
		std::cout << "ERROR Create Task" << std::endl;
		return -1;
	}

	// 2 : Create Digital out
	std::cout << "...: Create DigitalOut :..." << std::endl;
	if ((error = DAQmxCreateDOChan(valve2Handle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines)) < 0)
	{
		std::cout << "ERROR Create DigitalOut" << std::endl;
		std::cout << (int)error << std::endl;
		return -1;
	}

	// 3 : Start Task
	if (DAQmxStartTask(valve2Handle) < 0)
	{
		std::cout << "ERROR Start Task" << std::endl;
		return -1;
	}

	uint32_t valveAction = 0x02; //0010, 1rst led is off but 2nd is on

	// 4 : Write
	if (DAQmxWriteDigitalScalarU32(valve2Handle, true, 10, valveAction, NULL) < 0)
	{
		std::cout << "ERROR Write Digital (1)" << std::endl;
		return -1;
	}

	Sleep(2000);

	valveAction = 0x00; //0000; all led are off.
	if (DAQmxWriteDigitalScalarU32(valve2Handle, true, 10, valveAction, NULL) < 0)
	{
		std::cout << "ERROR Write Digital (2)" << std::endl;
		return -1;
	}

	// 5 : Stop Task
	if (DAQmxStopTask(valve2Handle) < 0)
	{
		std::cout << "ERROR Stop Task" << std::endl;
		return -1;
	}

	// 6 : Clear Task
	if (DAQmxClearTask(valve2Handle) < 0)
	{
		std::cout << "ERROR Clear Task" << std::endl;
		return -1;
	}

	std::cout << "...: Program Finished Ok :...";

}

/*
Turn on 2 leds, and turn off with 2sec interval
*/
int Q2_3()
{
	TaskHandle valve2Handle;
	int32 error;
	// 1 : Create Task
	std::cout << "...: Create Task :..." << std::endl;
	if (DAQmxCreateTask("", &valve2Handle) < 0)
	{
		std::cout << "ERROR Create Task" << std::endl;
		return -1;
	}

	// 2 : Create Digital out
	std::cout << "...: Create DigitalOut :..." << std::endl;
	if ((error = DAQmxCreateDOChan(valve2Handle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines)) < 0)
	{
		std::cout << "ERROR Create DigitalOut" << std::endl;
		std::cout << (int)error << std::endl;
		return -1;
	}

	// 3 : Start Task
	if (DAQmxStartTask(valve2Handle) < 0)
	{
		std::cout << "ERROR Start Task" << std::endl;
		return -1;
	}

	// 4 : Write
	uint32_t valveAction = 0x06;  // Both bits 0 and 1 set (binary 0110)
	if (DAQmxWriteDigitalScalarU32(valve2Handle, true, 10, valveAction, NULL) < 0)
	{
		std::cout << "ERROR Write Digital (1)" << std::endl;
		return -1;
	}

	Sleep(2000);

	valveAction = 0x04; //0100, 2nd led is off
	if (DAQmxWriteDigitalScalarU32(valve2Handle, true, 10, valveAction, NULL) < 0)
	{
		std::cout << "ERROR Write Digital (2)" << std::endl;
		return -1;
	}

	Sleep(2000);

	valveAction = 0x00; //turn off all
	if (DAQmxWriteDigitalScalarU32(valve2Handle, true, 10, valveAction, NULL) < 0)
	{
		std::cout << "ERROR Write Digital (2)" << std::endl;
		return -1;
	}

	// 5 : Stop Task
	if (DAQmxStopTask(valve2Handle) < 0)
	{
		std::cout << "ERROR Stop Task" << std::endl;
		return -1;
	}

	// 6 : Clear Task
	if (DAQmxClearTask(valve2Handle) < 0)
	{
		std::cout << "ERROR Clear Task" << std::endl;
		return -1;
	}

	std::cout << "...: Program Finished Ok :...";

	return 0;
}

int truc()
{
	TaskHandle valve2Handle;
	int32 error;
	// 1 : Create Task
	std::cout << "...: Create Task :..." << std::endl;
	if (DAQmxCreateTask("", &valve2Handle) < 0)
	{
		std::cout << "ERROR Create Task" << std::endl;
		return -1;
	}

	// 2 : Create Digital In
	std::cout << "...: Create DigitalIn :..." << std::endl;
	if ((error = DAQmxCreateDIChan(valve2Handle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines)) < 0)
	{
		std::cout << "ERROR Create DigitalIn" << std::endl;
		std::cout << (int)error << std::endl;
		return -1;
	}

	// 3 : Start Task
	if (DAQmxStartTask(valve2Handle) < 0)
	{
		std::cout << "ERROR Start Task" << std::endl;
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		uInt32 value;
		DAQmxReadDigitalScalarU32(valve2Handle, 1000, &value, NULL);
		std::cout << value << " " << std::hex << value << std::dec << std::endl;
		Sleep(1000);
	}

	// 5 : Stop Task
	if (DAQmxStopTask(valve2Handle) < 0)
	{
		std::cout << "ERROR Stop Task" << std::endl;
		return -1;
	}

	// 6 : Clear Task
	if (DAQmxClearTask(valve2Handle) < 0)
	{
		std::cout << "ERROR Clear Task" << std::endl;
		return -1;
	}

	std::cout << "...: Program Finished Ok :...";

	return 0;
}

void test()
{
	CEsMelangeur* pignatPtr = nullptr;

	try {
		pignatPtr = new CEsMelangeur;
	}
	catch (const char* e)
	{
		std::cout << e;
		return;
	}

	std::cout << "FIN";
	pignatPtr->fermerEsMelangeur();
	std::cout << "Fermer";
}
#pragma endregion

void ShowEntries(CEsMelangeur& pignat)
{
	for (int i = 0; i < 10; i++)
	{
		system("cls");
		std::cout << "........:________Lecture#" << (i+1) << "________:........" << std::endl;
		pignat.lireEntrees();

		std::cout << "Capteur Bas R1 : " << pignat.getCapteurBasR1() << std::endl
			<< "Capteur Bas R2 : " << pignat.getCapteurBasR2() << std::endl
			<< "Capteur Bas R3 : " << pignat.getCapteurBasR3() << std::endl
			<< "Capteur Niveau Bas : " << pignat.getCapteurNiveauBas() << std::endl
			<< "Capteur Niveau Haut : " << pignat.getCapteurNiveauHaut() << std::endl
			<< "Marche : " << pignat.getMarche() << std::endl
			<< "Arret : " << pignat.getArret() << std::endl
			<< "Manuel auto : " << pignat.getManuelAuto() << std::endl
			<< "Poids (g) : " << pignat.getPoids() << std::endl;

		Sleep(1000);
	}
}

void SetAnOutput(CEsMelangeur& pignat, char action)
{
	system("cls");
	std::cout << "........:________Ecriture________:........" << std::endl;

	std::string name = "";

	switch (action)
	{
		case '1': name = "Vanne PVC Base"; break;
		case '2': name = "Vanne PVC Base FD"; break;
		case '3': name = "Vanne Plastifiant"; break;
		case '4': name = "Vanne Lubrifiant"; break;
		case '5': name = "Vanne Vidange"; break;
		case '6': name = "Malaxeur"; break;
		case '7': name = "Evacuation"; break;
		case '8': name = "Voyant Rouge"; break;
	}

	std::cout << "Souhaitez vous Allumer ou Eteindre : " << name << " ?" << std::endl
		<< "[1] Allumer \n[0] Eteindre" << std::endl;

	char choice = '0';
	std::cin >> choice;
	std::cin.clear();

	bool etat = choice == '1';

	switch (action)
	{
		case '1': pignat.setVannePVCBase(etat); break;
		case '2': pignat.setVannePVCBaseFD(etat); break;
		case '3': pignat.setVannePlastifiant(etat); break;
		case '4': pignat.setVanneLubrifiant(etat); break;
		case '5': pignat.setVanneVidange(etat); break;
		case '6': pignat.setMalaxeur(etat); break;
		case '7': pignat.setEvacuation(etat); break;
		case '8': pignat.setVoyantRouge(etat); break;
	}

	if (etat)
		std::cout << name << " allum\202." << std::endl;
	else 
		std::cout << name << " \202teint." << std::endl;


	pignat.majSorties();
	Sleep(1500);
}

void AskCycle(CEsMelangeur& pignat)
{
	int masse_pvc_base = 0, masse_plastifiant = 0, masse_lubrifiant = 0, temps_malaxage = 0, temps_refroidissement = 0;

	system("cls");
	std::cout << "........:________Lancer Cycle________:........" << std::endl;

	std::cout << "Choisir masse_pvp_base (g)" << std::endl;
	std::cin >> masse_pvc_base;

	std::cout << "Choisir masse_plastifiant (g)" << std::endl;
	std::cin >> masse_plastifiant;

	std::cout << "Choisir masse_lubrifiant (g)" << std::endl;
	std::cin >> masse_lubrifiant;

	std::cout << "Choisir temps_malaxage (s)" << std::endl;
	std::cin >> temps_malaxage;

	std::cout << "Choisir temps_refroidissement (s)" << std::endl;
	std::cin >> temps_refroidissement;

	std::cout << "........:________Cycle en cours________:........" << std::endl;
	pignat.lancerCycleFabrication(masse_pvc_base, masse_plastifiant, masse_lubrifiant, temps_malaxage, temps_refroidissement);
	std::cout << "........:________Cycle Fini________:........" << std::endl;
}

int main()
{
	CEsMelangeur pignat;
	int error = 0;

	//Init pignat
	error = pignat.initEsMelangeur();
	if (error != 0)
	{
		std::cout << "Error : " << error << " " << pignat.texteErreur(error);
		return error;
	}

	//Turn off outputs
	error = pignat.majSorties();
	if (error != 0)
	{
		std::cout << "Error : " << error << " " << pignat.texteErreur(error);
		return error;
	}

	//Update Entries
	error = pignat.lireEntrees();
	if (error != 0)
	{
		std::cout << "Error : " << error << " " << pignat.texteErreur(error);
		return error;
	}

	//Menu
	std::cout << "Machine Initialis\202e" << std::endl;

	char action = '0';
	bool running = true;

	while (running)
	{
		std::cout << "........:Choisir ce que vous souhaitez faire:........" << std::endl;

		std::cout << "[0] Lire les entr\202es" << std::endl;
		std::cout << "[1] G\202rer Vanne PVC Base" << std::endl;
		std::cout << "[2] G\202rer Vanne PVC Base FD" << std::endl;
		std::cout << "[3] G\202rer Vanne Plastifiant" << std::endl;
		std::cout << "[4] G\202rer Vanne Lubrifiant" << std::endl;
		std::cout << "[5] G\202rer Vanne Vidange" << std::endl;
		std::cout << "[6] G\202rer Vanne Malaxeur" << std::endl;
		std::cout << "[7] G\202rer Vanne Evacuation" << std::endl;
		std::cout << "[8] G\202rer Vanne Voyant Rouge" << std::endl;
		std::cout << "[9] Cycle Complet" << std::endl;
		std::cout << "[n] Quitter" << std::endl;

		std::cin >> action;
		std::cin.clear();

		switch (action)
		{
			case '0': ShowEntries(pignat); break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8': SetAnOutput(pignat, action); break;
			case '9': AskCycle(pignat); break;
			default: running = false;
		}

		system("cls");
	}

	std::cout << "........:Fermtures des sorties:........" << std::endl;

	//Turn off outputs
	pignat.setVannePVCBase(false);
	pignat.setVannePVCBaseFD(false);
	pignat.setVannePlastifiant(false);
	pignat.setVanneLubrifiant(false);
	pignat.setVanneVidange(false);
	pignat.setMalaxeur(false);
	pignat.setEvacuation(false);
	pignat.setVoyantRouge(false);
	error = pignat.majSorties();
	if (error < 0)
	{
		std::cout << "Error : " << error << " " << pignat.texteErreur(error);
		return error;
	}

	//Stop Machine
	error = pignat.fermerEsMelangeur();
	if (error < 0)
	{
		std::cout << "Error : " << error << " " << pignat.texteErreur(error);
		return error;
	}

	std::cout << "........:Fin du programme:........" << std::endl;

	return 0;
	
}