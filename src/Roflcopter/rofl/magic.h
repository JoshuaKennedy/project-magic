// Project Magic Runtime Header File
// Copyright 2010-2012 Joshua Kennedy. All rights reserved.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#pragma comment(lib, "magic1.lib")

#include <Windows.h>

// Console Library

// The available colors for the console.
enum ConsoleColors
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGrey = 7,
	DarkGrey = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15,
	Blink = 128,
};

// Shows the console window.
extern __declspec (dllimport) void ShowConsole();

// Hides the console window, but doesn't close it.
extern __declspec (dllimport) void HideConsole();

// Maximizes the console window.
extern __declspec (dllimport) void MaximizeConsole();

// Minimizes the console window.
extern __declspec (dllimport) void MinimizeConsole();

// Restores the console window.
extern __declspec (dllimport) void RestoreConsole();

// Moves the console cursor to the specified coordinate on the console.
extern __declspec (dllimport) void ConsoleSetCursorPosition(int x, int y);

// Clears the console buffers, and moves the console cursor to the upper left corner.
extern __declspec (dllimport) void ClearConsole();

// Moves the console window to specified coordinate on the screen.
extern __declspec (dllimport) void MoveConsoleWindow(int x, int y);

// Resizes the console to the specified width and height.
extern __declspec (dllimport) void ChangeConsoleSize(int width, int height);

// Sets console colors to the ones specified. List of possible colors are in the enum ConsoleColors.
extern __declspec (dllimport) void SetConsoleColors(int fg, int bg);

// Resets the console colors to the default colors. foreground: LightGrey, background: Black.
extern __declspec (dllimport) void ResetConsoleColors();

// Turns the blinking cursor '_' on or off.
extern __declspec (dllimport) void SetConsoleCursorVisible(BOOL visible);

// Halts execution of current console thread with message and waits for a keypress.
extern __declspec (dllimport) void PauseConsoleWithMessage(const char* message);

// Same as above, except with a default message, "Press any key to continue . . . ".
extern __declspec (dllimport) void PauseConsole();

// Audio Library

// Plays a wave-form audio file.
extern __declspec (dllimport) void PlayWAVFile(LPCWSTR file, BOOL synchrous);

// Cryptography Library (provided by the WinCrypt API)
extern __declspec (dllimport) const char* GetMD5Hash(char* input);

// String Functions

// Duplicates (and allocates memory for) string s up to n characters.
// Derived from http://opensource.apple.com/source/gcc/gcc-5664/libiberty/strndup.c
extern __declspec(dllimport) char* strndup(const char *s, size_t n);

// Returns a string from str, between positions begin and len.
extern __declspec(dllimport) char* substring(const char* str, size_t begin, size_t len);

// System Processor Library

// Gets the number of cores available to the system. (Gets both physical and virtual cores)
extern __declspec (dllimport) int GetNumberOfCores();

// Detects if 3D-Now is present.
extern __declspec (dllimport) BOOL Is3DNowPresent();

// Detects if MMX is present.
extern __declspec (dllimport) BOOL IsMMXPresent();

// Detects if DEP is enabled.
extern __declspec (dllimport) BOOL IsDEPEnabled();

// Detects if DAE is enabled.
extern __declspec (dllimport) BOOL IsDAEEnabled();

// Detects if SSE3 is present.
extern __declspec (dllimport) BOOL IsSSE3Present();

// Detects if Virtualization is enabled.
extern __declspec (dllimport) BOOL IsVirtualizationEnabled();

// Detects if SSE is present.
extern __declspec (dllimport) BOOL IsSSEPresent();

// Detects if SSE2 is present.
extern __declspec (dllimport) BOOL IsSSE2Present();

// Detects if XSAVE is enabled.
extern __declspec (dllimport) BOOL IsXSAVEEnabled();

// Checks if the system is 64-bit. (Throws a runtime error if IsWow64Process isn't found in KERNEL32.dll, only on older systems.)
extern __declspec (dllimport) BOOL IsWow64();

// Gets the number of processor cores.
extern "C" __declspec(dllexport) int GetProcessorCoreCount();

// Gets the number of logical processors.
extern "C" __declspec(dllexport) int GetLogicalProcessorCount();

// Returns the processor vendor ID, like "GenuineIntel", "AuthenticAMD", or others.
//extern __declspec(dllimport) const char* GetProcessorVendorID();

// System Power API

// Shuts down (and turns off?) the computer.
extern __declspec (dllimport) void ShutdownComputer();

// Restarts the computer.
extern __declspec (dllimport) void RebootComputer();

// Locks the computer.
extern __declspec (dllimport) void LockComputer();

// Logs the current user off of the computer.
extern __declspec (dllimport) void LogoffComputer();

// Enumeration of available power statuses.
enum PowerStatus
{
	PluggedIn = 0, // The laptop is connected to an AC or DC power source.
	OnBattery = 1, // The laptop isn't connected to a power source and is running on battery.
	NotLaptop = 2, // The system isn't a laptop.
};

// Gets the percentage of the remaining battery as an integer between 0 and 100.
extern __declspec (dllimport) int GetBatteryPercentage();

// Returns a value from PowerStatus.
extern __declspec (dllimport) PowerStatus GetPowerStatus();

// System Debug API

// Returns if a remote or local debugger is attached to the host process.
extern __declspec(dllimport) inline BOOL IsDebuggerAttached();

extern __declspec (dllimport) inline BOOL IsLocalDebuggerAttached();
extern __declspec (dllimport) inline BOOL IsRemoteDebuggerAttached();
extern __declspec (dllimport) inline void ErasePEHeaderFromMemory();
extern __declspec (dllimport) void EnableDebugPrivileges();
extern __declspec (dllimport) void printfDebug(const char* szFormat, ...);

#ifdef __cplusplus
}
#endif
