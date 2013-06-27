// rofl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// We set everything up.

	SetConsoleTitleA("ROFLCOPTER!"); // Set the title bar text.

	// We build the skeleton of our roflcopter.

	printf("         :LOL:         \n");
	printf("           ^           \n");
	printf("     /-----------      \n");
	printf(" O ===       [ ] \\    \n");
	printf("      \\           \\  \n");
	printf("       \\___________]  \n");
	printf("           I     I     \n");
	printf("       \\-----------/  \n");
	
	// This is our draw loop.
	while(1)
	{
		// draw the invisible
		ConsoleSetCursorPosition(0, 0);
		printf("         ");
		ConsoleSetCursorPosition(14, 0);
		printf("         ");
		ConsoleSetCursorPosition(0, 2);
		printf(" L ");
		ConsoleSetCursorPosition(0, 3);
		printf(" O ");
		ConsoleSetCursorPosition(0, 4);
		printf(" L ");
		Sleep(75);

		// draw the visible
		ConsoleSetCursorPosition(0, 0);
		printf("ROFL:ROFL");
		ConsoleSetCursorPosition(14, 0);
		printf("ROFL:ROFL");
		ConsoleSetCursorPosition(0, 2);
		printf("   ");
		ConsoleSetCursorPosition(0, 3);
		printf("LOL");
		ConsoleSetCursorPosition(0, 4);
		printf("   ");
		Sleep(75);
	}
}
