#include "stdafx.h"

extern "C" __declspec(dllexport) int GetNumberOfCores()
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo( &sysinfo );

	return sysinfo.dwNumberOfProcessors;
}

extern "C" __declspec(dllexport) BOOL Is3DNowPresent()
{
	return IsProcessorFeaturePresent(PF_3DNOW_INSTRUCTIONS_AVAILABLE);
}

extern "C" __declspec(dllexport) BOOL IsMMXPresent()
{
	return IsProcessorFeaturePresent(PF_MMX_INSTRUCTIONS_AVAILABLE);
}

extern "C" __declspec(dllexport) BOOL IsDEPEnabled()
{
	return IsProcessorFeaturePresent(PF_NX_ENABLED);
}

extern "C" __declspec(dllexport) BOOL IsDAEEnabled()
{
	return IsProcessorFeaturePresent(PF_PAE_ENABLED);
}

extern "C" __declspec(dllexport) BOOL IsSSE3Present()
{
	return IsProcessorFeaturePresent(PF_SSE3_INSTRUCTIONS_AVAILABLE);
}

extern "C" __declspec(dllexport) BOOL IsVirtualizationEnabled()
{
	return IsProcessorFeaturePresent(21);
}

extern "C" __declspec(dllexport) BOOL IsSSEPresent()
{
	return IsProcessorFeaturePresent(PF_XMMI_INSTRUCTIONS_AVAILABLE);
}

extern "C" __declspec(dllexport) BOOL IsSSE2Present()
{
	return IsProcessorFeaturePresent(PF_XMMI64_INSTRUCTIONS_AVAILABLE);
}

extern "C" __declspec(dllexport) BOOL IsXSAVEEnabled()
{
	return IsProcessorFeaturePresent(PF_XSAVE_ENABLED);
}

typedef BOOL (WINAPI* LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

LPFN_ISWOW64PROCESS fnIsWow64Process;

extern "C" __declspec(dllexport) BOOL IsWow64()
{
    BOOL bIsWow64 = FALSE;

    // IsWow64Process is not available on all supported versions of Windows.
    // Use GetModuleHandle to get a handle to the DLL that contains the function
    // and GetProcAddress to get a pointer to the function if available.

    fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "IsWow64Process");

    if(NULL != fnIsWow64Process)
    {
        if (!fnIsWow64Process(GetCurrentProcess(), &bIsWow64))
        {
            //MessageBox(NULL, L"The target system doesn't support IsWow64Process!", L"Project Magic Runtime Error", MB_ICONSTOP | MB_OK);
			return NULL;
        }
    }

    return bIsWow64;
}

typedef BOOL (WINAPI *LPFN_GLPI)(
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION, 
    PDWORD);


// Helper function to count set bits in the processor mask.
DWORD CountSetBits(ULONG_PTR bitMask)
{
    DWORD LSHIFT = sizeof(ULONG_PTR)*8 - 1;
    DWORD bitSetCount = 0;
    ULONG_PTR bitTest = (ULONG_PTR)1 << LSHIFT;    
    DWORD i;
    
    for (i = 0; i <= LSHIFT; ++i)
    {
        bitSetCount += ((bitMask & bitTest)?1:0);
        bitTest/=2;
    }

    return bitSetCount;
}

extern "C" __declspec(dllexport) int GetProcessorCoreCount()
{
	LPFN_GLPI glpi;
	BOOL done = FALSE;
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION buffer = NULL;
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION ptr = NULL;
	DWORD returnLength = 0;
	DWORD logicalProcessorCount = 0;
	DWORD processorCoreCount = 0;
	DWORD byteOffset = 0;

	glpi = (LPFN_GLPI) GetProcAddress(GetModuleHandle(TEXT("kernel32")), "GetLogicalProcessorInformation");
    if (NULL == glpi) 
    {
        return -1;
    }

	while (!done)
    {
        DWORD rc = glpi(buffer, &returnLength);

        if (FALSE == rc) 
        {
            if (GetLastError() == ERROR_INSUFFICIENT_BUFFER) 
            {
                if (buffer) 
                    free(buffer);

                buffer = (PSYSTEM_LOGICAL_PROCESSOR_INFORMATION)malloc(
                        returnLength);

                if (NULL == buffer) 
                {
                    //_tprintf(TEXT("\nError: Allocation failure\n"));
					printfDebug("Magic - Error: Allocation failure.\n");
                    return -2;
                }
            } 
            else 
            {
                //_tprintf(TEXT("\nError %d\n"), GetLastError());
				printfDebug("Magic - Error: %d\n", GetLastError());
                return -3;
            }
        } 
        else
        {
            done = TRUE;
        }
    }

	ptr = buffer;

	while (byteOffset + sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION) <= returnLength) 
    {
        switch (ptr->Relationship) 
        {
		case RelationProcessorCore:
            processorCoreCount++;

            // A hyperthreaded core supplies more than one logical processor.
            logicalProcessorCount += CountSetBits(ptr->ProcessorMask);
            break;
		}

		byteOffset += sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
        ptr++;
	}

	return processorCoreCount;
}

extern "C" __declspec(dllexport) int GetLogicalProcessorCount()
{
	LPFN_GLPI glpi;
	BOOL done = FALSE;
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION buffer = NULL;
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION ptr = NULL;
	DWORD returnLength = 0;
	DWORD logicalProcessorCount = 0;
	DWORD processorCoreCount = 0;
	DWORD byteOffset = 0;

	glpi = (LPFN_GLPI) GetProcAddress(GetModuleHandle(TEXT("kernel32")), "GetLogicalProcessorInformation");
    if (NULL == glpi) 
    {
        return -1;
    }

	while (!done)
    {
        DWORD rc = glpi(buffer, &returnLength);

        if (FALSE == rc) 
        {
            if (GetLastError() == ERROR_INSUFFICIENT_BUFFER) 
            {
                if (buffer) 
                    free(buffer);

                buffer = (PSYSTEM_LOGICAL_PROCESSOR_INFORMATION)malloc(
                        returnLength);

                if (NULL == buffer) 
                {
                    //_tprintf(TEXT("\nError: Allocation failure\n"));
					printfDebug("Magic - Error: Allocation failure.\n");
                    return -2;
                }
            } 
            else 
            {
                //_tprintf(TEXT("\nError %d\n"), GetLastError());
				printfDebug("Magic - Error: %d\n", GetLastError());
                return -3;
            }
        } 
        else
        {
            done = TRUE;
        }
    }

	ptr = buffer;

	while (byteOffset + sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION) <= returnLength) 
    {
        switch (ptr->Relationship) 
        {
		case RelationProcessorCore:
            processorCoreCount++;

            // A hyperthreaded core supplies more than one logical processor.
            logicalProcessorCount += CountSetBits(ptr->ProcessorMask);
            break;
		}

		byteOffset += sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
        ptr++;
	}

	return logicalProcessorCount;
}
