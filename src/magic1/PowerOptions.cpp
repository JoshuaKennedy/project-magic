#include "stdafx.h"

extern "C" __declspec (dllexport) void ShutdownComputer()
{
	InitiateSystemShutdown(NULL, NULL, 0, TRUE, FALSE);
}

extern "C" __declspec (dllexport) void RebootComputer()
{
	InitiateSystemShutdown(NULL, NULL, 0, TRUE, TRUE);
}

extern "C" __declspec (dllexport) void LockComputer()
{
	LockWorkStation();
}

extern "C" __declspec (dllexport) void LogoffComputer()
{
	ExitWindowsEx(EWX_LOGOFF, SHTDN_REASON_MAJOR_APPLICATION);
}

extern "C" __declspec (dllexport) int GetBatteryPercentage()
{
	SYSTEM_POWER_STATUS spsPwr;
	GetSystemPowerStatus(&spsPwr);
	return spsPwr.BatteryLifePercent;
}

extern "C" __declspec (dllexport) PowerStatus GetPowerStatus()
{
	SYSTEM_POWER_STATUS spsPwr;
	GetSystemPowerStatus(&spsPwr);

	if (spsPwr.ACLineStatus == 0)
	{
		return PowerStatus::OnBattery;
	}
	else if (spsPwr.ACLineStatus == 1)
	{
		return PowerStatus::PluggedIn;
	}
	else
	{
		return PowerStatus::NotLaptop;
	}
}
