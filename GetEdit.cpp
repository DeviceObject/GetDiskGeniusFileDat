#include "stdafx.h"
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	HWND hWindow;
	HANDLE hFile;
	BOOLEAN bRet;
	ULONG ulRet;

	CHAR szDat[0x15000] = {0};
	hFile = INVALID_HANDLE_VALUE;
	bRet = FALSE;
	ulRet = 0;

	hWindow = FindWindowA(NULL,"UtilsApi.c");
	if (hWindow)
	{
		::SendMessageA((HWND)0x00040EDC,WM_GETTEXT,0x15000,(LPARAM)szDat);
		
	}
	hFile = CreateFileA("UtilsApi.c", \
		FILE_WRITE_ACCESS, \
		FILE_SHARE_READ, \
		NULL, \
		OPEN_ALWAYS, \
		FILE_ATTRIBUTE_NORMAL, \
		NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return 0;
	}
	bRet = WriteFile(hFile,szDat,0x15000,&ulRet,NULL);
	if (FALSE == bRet)
	{
		CloseHandle(hFile);
		return 0;
	}
	CloseHandle(hFile);
	return 0;
}

