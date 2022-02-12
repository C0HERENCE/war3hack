#include <cstdio>
#include <Windows.h>
#include <TlHelp32.h>
#include "jass/jass_vm.h"
#include "jass/global_variable.h"

DWORD GetW3TlsForIndex(DWORD index);

void main()
{
	printf("start\n");
	// get game.dll base address
	uint32_t hGameDll = (uint32_t)GetModuleHandleA("Game.dll");
	printf("%p\n", hGameDll);

	// get&set Tls
	auto tlsIndex = *(DWORD *)(0xBB8628 + hGameDll);
	TlsSetValue(tlsIndex, (LPVOID)GetW3TlsForIndex(tlsIndex));

	// set GetInstance address in jass_vm.h
	GetInstance = (_GetInstance)(hGameDll + 0x4efb0);
	printf("%p\n", GetInstance);

	// get global table
	auto global_table = get_jass_vm()->global_table;
	printf("%p\n", global_table);

	int xb=0;
	for (auto it = global_table->begin();it != global_table->end(); ++it)
	{
		global_variable gv((variable_node*)(&(*it)));
		printf("%d: %s\n", xb++, gv.name());
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	AllocConsole();
	FILE *fDummy;
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);
	freopen_s(&fDummy, "CONOUT$", "w", stdout);
	if (ul_reason_for_call == ul_reason_for_call)
		main();
	return TRUE;
}


DWORD GetW3TlsForIndex(DWORD index)
{
	DWORD pid = GetCurrentProcessId();
	THREADENTRY32 te32;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, pid);
	te32.dwSize = sizeof(THREADENTRY32);

	if (Thread32First(hSnap, &te32))
	{
		do
		{
			if (te32.th32OwnerProcessID == pid)
			{
				HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, false, te32.th32ThreadID);
				CONTEXT ctx = {CONTEXT_SEGMENTS};
				LDT_ENTRY ldt;
				GetThreadContext(hThread, &ctx);
				GetThreadSelectorEntry(hThread, ctx.SegFs, &ldt);
				DWORD dwThreadBase = ldt.BaseLow | (ldt.HighWord.Bytes.BaseMid << 16) | (ldt.HighWord.Bytes.BaseHi << 24);
				CloseHandle(hThread);
				if (dwThreadBase == NULL)
					continue;
				DWORD *dwTLS = *(DWORD **)(dwThreadBase + 0xE10 + 4 * index);
				if (dwTLS == NULL)
					continue;
				return (DWORD)dwTLS;
			}
		} while (Thread32Next(hSnap, &te32));
	}

	return NULL;
}
