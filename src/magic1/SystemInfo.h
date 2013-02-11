#pragma once

extern "C" __declspec(dllexport) int GetNumberOfCores();
extern "C" __declspec(dllexport) BOOL Is3DNowPresent();
extern "C" __declspec(dllexport) BOOL IsMMXPresent();
extern "C" __declspec(dllexport) BOOL IsDEPEnabled();
extern "C" __declspec(dllexport) BOOL IsDAEEnabled();
extern "C" __declspec(dllexport) BOOL IsSSE3Present();
extern "C" __declspec(dllexport) BOOL IsVirtualizationEnabled();
extern "C" __declspec(dllexport) BOOL IsSSEPresent();
extern "C" __declspec(dllexport) BOOL IsSSE2Present();
extern "C" __declspec(dllexport) BOOL IsXSAVEEnabled();
extern "C" __declspec(dllexport) BOOL IsWow64();
extern "C" __declspec(dllexport) int GetProcessorCoreCount();
extern "C" __declspec(dllexport) int GetLogicalProcessorCount();
