/*
 * Disclaimer:
 * This code was created for educational purposes only.
 * The author does not take responsibility for any misuse 
 * or unintended consequences arising from its application.
 * Users are encouraged to exercise caution and adhere to 
 * all relevant laws and regulations when utilizing this code.
 */

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

        INT ReturnValue = Inj(Pid, DllPath);
		
	return 0;
}
