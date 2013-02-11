#include "stdafx.h"

extern "C" __declspec (dllexport) inline BOOL IsDebuggerAttached()
{
	BOOL remoteDebugger;
	CheckRemoteDebuggerPresent(GetCurrentProcess(), &remoteDebugger);
	return IsDebuggerPresent() || remoteDebugger;
}

extern "C" __declspec (dllexport) inline BOOL IsLocalDebuggerAttached()
{
	return IsDebuggerPresent();
}

extern "C" __declspec (dllexport) inline BOOL IsRemoteDebuggerAttached()
{
	BOOL remoteDebugger;
	CheckRemoteDebuggerPresent(GetCurrentProcess(), &remoteDebugger);
	return remoteDebugger;
}

extern "C" __declspec (dllexport) inline void ErasePEHeaderFromMemory()
{
	DWORD OldProtect = 0;
    
    // Get base address of module
    char *pBaseAddr = (char*)GetModuleHandle(NULL);

    // Change memory protection
    VirtualProtect(pBaseAddr, 4096, // Assume x86 page size
            PAGE_READWRITE, &OldProtect);

    // Erase the header
    ZeroMemory(pBaseAddr, 4096);
}

extern "C" __declspec (dllexport) void EnableDebugPrivileges()
{
    HANDLE hToken;
    LUID luid;
    TOKEN_PRIVILEGES tkp;

    OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);

    LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid);

    tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Luid = luid;
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    AdjustTokenPrivileges(hToken, false, &tkp, sizeof(tkp), NULL, NULL);

    CloseHandle(hToken); 
}

extern "C" __declspec (dllexport) void printfDebug(const char* szFormat, ...)
{
	char szBuff[4096];
    va_list arg;
    va_start(arg, szFormat);
    _vsnprintf(szBuff, sizeof(szBuff), szFormat, arg);
    va_end(arg);

    OutputDebugStringA(szBuff);
}
