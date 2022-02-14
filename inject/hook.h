#ifndef INJECT_HOOK_H
#define INJECT_HOOK_H

#include <Minhook.h>

namespace inject{
    typedef void* hook_t;
    bool install(uintptr_t* pointer_ptr, uintptr_t detour, hook_t* ph = nullptr);
    bool uninstall(hook_t* ph);
}

#endif