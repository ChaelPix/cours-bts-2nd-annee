#include <iostream>
#include <Windows.h>

#include "NIDAQmx.h"

#include "EsMelangeur.h"

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
	std::cout << "Machine Initialisée" << std::endl;


	std::cout << "Choisir ce que vous souhaitez faire";


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

	return 0;
	
}