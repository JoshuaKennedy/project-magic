#pragma once

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

extern "C" __declspec (dllexport) void ShowConsole();
extern "C" __declspec (dllexport) void HideConsole();
extern "C" __declspec (dllexport) void MaximizeConsole();
extern "C" __declspec (dllexport) void MinimizeConsole();
extern "C" __declspec (dllexport) void RestoreConsole();
extern "C" __declspec (dllexport) void ConsoleSetCursorPosition(int x, int y);
extern "C" __declspec (dllexport) void ClearConsole();
extern "C" __declspec (dllexport) void MoveConsoleWindow(int x, int y);
extern "C" __declspec (dllexport) void ChangeConsoleSize(int width, int height);
extern "C" __declspec (dllexport) void SetConsoleColors(int fg, int bg);
extern "C" __declspec (dllexport) void ResetConsoleColors();
extern "C" __declspec (dllexport) void SetConsoleCursorVisible(BOOL visible);
extern "C" __declspec (dllexport) void PauseConsoleWithMessage(const char* message);
extern "C" __declspec (dllexport) void PauseConsole();
