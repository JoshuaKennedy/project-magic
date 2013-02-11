#include "stdafx.h"

extern "C" __declspec (dllexport) void PlayWAVFile(LPCWSTR file, BOOL synchrous)
{
	int args;
	if (synchrous == TRUE)
	{
		args = SND_SYNC;
	}
	else
	{
		args = SND_ASYNC;
	}

	PlaySound(file, NULL, args);
}

//extern "C" __declspec (dllexport) void PlayMP3File(LPCWSTR file)
//{
//	HWND m_Video = MCIWndCreate(NULL, GetModuleHandle(NULL), WS_CHILD | WS_VISIBLE | MCIWNDF_NOPLAYBAR | MCIWNDF_NOMENU, file);
//	MCIWndPlay(m_Video);
//	Sleep(10000);
//	MCIWndDestroy(m_Video);
//
//	/*TCHAR command[4096];
//
//	wcscat(command, L"open ");
//
//	wcscat(command, file);
//
//	wcscat(command, L" alias song1");
//
//	mciSendString(command,NULL, 0, 0);*/
//}
