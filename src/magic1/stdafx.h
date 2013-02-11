// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

//#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <iostream>
#include <ostream>
#include <string>
#include <Windows.h>
#include <urlmon.h>
#include <WinInet.h>
#include <process.h>
#include <conio.h>
#include <wchar.h>
#include <WinCrypt.h>

using namespace std;

#include "Console.h"
#include "SystemInfo.h"
#include "Audio.h"
#include "PowerOptions.h"
#include "Cryptography.h"
#include "StringAPI.h"
#include "DebugAPI.h"

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "vfw32.lib")
