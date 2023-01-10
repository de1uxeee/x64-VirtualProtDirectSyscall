#include <Windows.h>
#include <stdio.h>

extern "C" inline void asm_ZwVirtProt();
extern "C" inline uintptr_t kernelBasePlusDE99E{}, openThreadTokenPlus40h{};
extern "C" inline BOOL asm_VirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect);

void exCall()
{
	/*AllocConsole();
	FILE* coutFile = nullptr;
	freopen_s(&coutFile, "CONOUT$", "w", stdout);
	SetConsoleTitleA("BE suck");*/

	kernelBasePlusDE99E = reinterpret_cast<uintptr_t>(GetModuleHandleA("KERNELBASE.dll")) + 0xDE99E;
	openThreadTokenPlus40h = reinterpret_cast<uintptr_t>(GetProcAddress(GetModuleHandleA("KERNELBASE.dll"), "OpenThreadToken")) + 0x40;

	DWORD oldProt{};
	asm_VirtualProtect(reinterpret_cast<PVOID>(0x7FF642823620), 0x10, PAGE_EXECUTE_READWRITE, &oldProt);
}

BOOL DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(static_cast<HMODULE>(hModule));
		exCall();
	}

	return TRUE;
}