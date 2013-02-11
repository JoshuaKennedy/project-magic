#pragma once

enum PowerStatus
{
	PluggedIn = 0,
	OnBattery = 1,
	NotLaptop = 2,
};

extern "C" __declspec (dllexport) void ShutdownComputer();
extern "C" __declspec (dllexport) void RebootComputer();
extern "C" __declspec (dllexport) void LockComputer();
extern "C" __declspec (dllexport) void LogoffComputer();
extern "C" __declspec (dllexport) int GetBatteryPercentage();
extern "C" __declspec (dllexport) PowerStatus GetPowerStatus();
