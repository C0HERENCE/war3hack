#include "hook.h"

namespace inject{

    
struct minhook
{
    minhook() { MH_Initialize(); }
    ~minhook() { MH_Uninitialize(); }
};
minhook mh;
struct hook_info
{
    uintptr_t target;
};
bool install(uintptr_t *pointer_ptr, uintptr_t detour, hook_t *ph)
{
    uintptr_t target = *pointer_ptr;
    MH_STATUS status;
    if ((status = MH_CreateHook((PVOID)target, (PVOID)detour, (PVOID *)pointer_ptr)) == MH_OK)
    {
        if ((status = MH_EnableHook((PVOID)target)) == MH_OK)
        {
            if (ph)
            {
                hook_info *hi = new hook_info;
                hi->target = target;
                *ph = hi;
            }
            return true;
        }
    }
    ::SetLastError(status);
    return false;
}

bool uninstall(hook_t *ph)
{
    if (!ph || !*ph)
    {
        ::SetLastError((DWORD)MH_UNKNOWN);
        return false;
    }
    hook_info *hi = *(hook_info **)ph;
    uintptr_t target = hi->target;
    MH_STATUS status;
    if ((status = MH_DisableHook((PVOID)target)) == MH_OK)
    {
        if ((status = MH_RemoveHook((PVOID)target)) == MH_OK)
        {
            delete hi;
            *ph = 0;
            return true;
        }
    }
    ::SetLastError(status);
    return false;
}

}