#pragma once

extern "C" __declspec (dllexport) BOOL IsDebuggerAttached();
extern "C" __declspec (dllexport) BOOL IsLocalDebuggerAttached();
extern "C" __declspec (dllexport) BOOL IsRemoteDebuggerAttached();
extern "C" __declspec (dllexport) inline void ErasePEHeaderFromMemory();
extern "C" __declspec (dllexport) void EnableDebugPrivileges();
extern "C" __declspec (dllexport) void printfDebug(const char* szFormat, ...);
