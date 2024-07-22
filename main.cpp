#include <Windows.h>
#include <stdio.h>
#include <cstdlib>
#include "Inj.h"

INT main(INT argc, PCHAR argv[])
{	
	
	printf("\n[+] Enter PID of process to inject and path to payload DLL.\n");
	printf("Example: DLLInject.exe 123 C :\\Users\\Public\\Payload.dll\n");

	if (argc != 3)
	{
		printf("\n[x] Incorrect number of arguments.\n");
		return 1;
	}

	DWORD Pid = atoi(argv[1]);
	PCHAR DllPath = argv[2];
	BOOL ReturnValue = FALSE;

        INT Retval = Inj(Pid, DllPath);
		
	return 0;
}
