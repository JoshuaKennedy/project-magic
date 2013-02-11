#include "magic.h"

#include <stdio.h>
#include <stdlib.h>
#include <ostream>
#include <iostream>
#include <conio.h>

BOOL IsHyperthreadingEnabled()
{
	int logical = GetLogicalProcessorCount();
	int physical = GetProcessorCoreCount();
	double division = logical / 2;

	if (logical == physical)
	{
		return FALSE;
	}
	else if (division == physical)
	{
		return TRUE;
	}
	else
		return NULL;
}

int main (int argc, char* argv[])
{
	//ErasePEHeaderFromMemory();
	int numCores = GetNumberOfCores();
	BOOL is64 = IsWow64();

	printf("# of cores: %d\n", numCores);
	printf ("System is ");
	if (is64 == TRUE)
	{
		printf("64-bit.\n");
	}
	else
	{
		printf("32-bit.\n");
	}

	PowerStatus status = GetPowerStatus();

	if (status == PowerStatus::PluggedIn)
	{
		int battery = GetBatteryPercentage();

		printf("Laptop is plugged in, and has a %d%% charge.\n", battery);
	}
	else if (status == PowerStatus::OnBattery)
	{
		int battery = GetBatteryPercentage();

		printf("Laptop is on battery with %d%% remaining.\n", battery);
	}
	else
	{
		printf("The system isn't a notebook computer!\n");
	}

	const char* hash = GetMD5Hash("Hello Jello");

	printf("The MD5 Hash of \"Hello Jello\" is: %s\n", hash);

	BOOL debug = IsDebuggerAttached();

	if (debug == TRUE)
		printf("Debugger is attached!\n");
	else
		printf("No debugger attached.\n");

	int logicalProcessors = GetLogicalProcessorCount();
	int coreCount = GetProcessorCoreCount();

	printf("Logical Processors: %d, Cores: %d\n", logicalProcessors, coreCount);

	BOOL hyperThread = IsHyperthreadingEnabled();

	if (hyperThread == TRUE)
		printf("Hyper-threading is enabled!\n");
	else
		printf("Hyper-threading is disabled.\n");

	ConsoleSetCursorPosition(20, 20);

	PauseConsole();
	return 0;
}
