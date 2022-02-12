#include "jass_vm.h"
#include <cstdio>

_GetInstance GetInstance;

// use GetInstance(5)
jass_vm_t* get_jass_vm(int index)
{
	uintptr_t ptr = GetInstance(5);
	uintptr_t vm = *(uintptr_t*)(*(uintptr_t*)(ptr + 0x90) + 0x04 * index);
	return vm ? (jass_vm_t*)(vm - ((true) ? 0 : 4)) : nullptr;
}

// use GetInstance(5)
jass_vm_t* get_jass_thread()
{
	uintptr_t ptr = GetInstance(5);
	int index = *(uintptr_t*)(ptr + 0x14);
	if (index == 0) {
		return 0;
	}
	return *(jass_vm_t**)(*(uintptr_t*)(ptr + 0x0C) + 4 * index - 4);
}

// use GetInstance(5)
native_func_table* get_native_function_hashtable()
{
    if (GetInstance == nullptr)
        printf("get_native_function_hashtable: GetInstance = null");
	return (native_func_table*)(GetInstance(5)+0x18);
}