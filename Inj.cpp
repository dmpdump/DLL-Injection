#include <Windows.h>
#include "Inj.h"


_Use_decl_annotations_ INT WINAPI Inj(ULONG Pid, PCHAR DLLPath)
{
	HMODULE hKernel32 = HMODULE();
	PVOID pLoadLibAddr = PVOID();
	HANDLE hTarget = HANDLE();
	PUCHAR pTarBuffer = {};
	SIZE_T PathLength = (strlen(DLLPath) + 1);
	SIZE_T BytesWrite = 0L;
	BOOL bWriteReturn = 0;
	HANDLE hThreadInTarget = HANDLE();
	LPDWORD ThreadBuff = 0L;
	BOOL ReturnValue = 0L;
	DWORD dwErr = 0;

	hKernel32 = GetModuleHandleW(L"kernel32.dll");

	pLoadLibAddr = GetProcAddress(hKernel32, "LoadLibraryA");

	hTarget = OpenProcess(PROCESS_VM_OPERATION|PROCESS_VM_WRITE|PROCESS_CREATE_THREAD, FALSE, Pid);

	pTarBuffer = (PUCHAR)VirtualAllocEx(hTarget, NULL, PathLength, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	bWriteReturn = WriteProcessMemory(hTarget, pTarBuffer, DLLPath, PathLength, &BytesWrite);

	hThreadInTarget = CreateRemoteThread(hTarget, 0, 0, LPTHREAD_START_ROUTINE(pLoadLibAddr), pTarBuffer, 0, ThreadBuff);

	CloseHandle(hTarget);
	CloseHandle(hThreadInTarget);

	return ReturnValue;
}