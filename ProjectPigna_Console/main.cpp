#include <iostream>
#include <Windows.h>

#include "NIDAQmx.h"

int main()
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
	if ((error=DAQmxCreateDOChan(valve2Handle, "Dev1/port0", "toto", DAQmx_Val_ChanForAllLines)) < 0)
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
	if (DAQmxWriteDigitalScalarU32(valve2Handle, true, 10, 1, NULL) < 0)
	{
		std::cout << "ERROR Write Digital (1)" << std::endl;
		return -1;
	}

	Sleep(2000);

	if(DAQmxWriteDigitalScalarU32(valve2Handle, true, 10, 0, NULL) < 0)
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