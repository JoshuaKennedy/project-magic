#include "stdafx.h"

extern "C" __declspec (dllexport) void ShowConsole()
{
	ShowWindow(GetConsoleWindow(), SW_SHOW);
}

extern "C" __declspec (dllexport) void HideConsole()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
}

extern "C" __declspec (dllexport) void MaximizeConsole()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

extern "C" __declspec (dllexport) void MinimizeConsole()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

extern "C" __declspec (dllexport) void RestoreConsole()
{
	ShowWindow(GetConsoleWindow(), SW_RESTORE);
}

extern "C" __declspec (dllexport) void ConsoleSetCursorPosition(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD PlaceCursorHere;
    PlaceCursorHere.X = x;
    PlaceCursorHere.Y = y;

    SetConsoleCursorPosition(hConsole, PlaceCursorHere);
}

extern "C" __declspec (dllexport) void ClearConsole()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };    /* here's where we'll home the
									cursor */
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */ 
	DWORD dwConSize;                 /* number of character cells in
									the current buffer */ 

	/* get the number of character cells in the current buffer */ 

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	/* fill the entire screen with blanks */ 

	FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);

	/* get the current text attribute */

	GetConsoleScreenBufferInfo(hConsole, &csbi);

	/* now set the buffer's attributes accordingly */ 

	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);

	/* put the cursor at (0, 0) */ 

	SetConsoleCursorPosition(hConsole, coordScreen);
}

extern "C" __declspec (dllexport) void MoveConsoleWindow(int x, int y)
{
	RECT r;
	GetWindowRect(GetConsoleWindow(), &r);

	MoveWindow(GetConsoleWindow(), x, y, r.right, r.bottom, TRUE);
}

extern "C" __declspec (dllexport) void ChangeConsoleSize(int width, int height)
{
	RECT r;
	GetWindowRect(GetConsoleWindow(), &r);

	MoveWindow(GetConsoleWindow(), r.left, r.top, width, height, TRUE);
}

extern "C" __declspec (dllexport) void SetConsoleColors(int fg, int bg)
{
	int color = fg + (bg * 16);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

extern "C" __declspec (dllexport) void ResetConsoleColors()
{
	SetConsoleColors(LightGrey, Black);
}

extern "C" __declspec (dllexport) void SetConsoleCursorVisible(BOOL visible)
{
	CONSOLE_CURSOR_INFO consoleCursorInfo;
	consoleCursorInfo.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(GENERIC_ALL), &consoleCursorInfo);
}

extern "C" __declspec (dllexport) void PauseConsoleWithMessage(const char* message)
{
	printf("%s", message);
	_getch();
	printf("\n");
}

extern "C" __declspec (dllexport) void PauseConsole()
{
	PauseConsoleWithMessage("Press any key to continue . . . ");
}
