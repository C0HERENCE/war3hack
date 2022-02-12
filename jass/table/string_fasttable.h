#ifndef JASS_STRING_FASTTABLE_H
#define JASS_STRING_FASTTABLE_H

#include <cstdint>

struct string_fasttable
{
    uint32_t unk_;
    uint32_t max_size_;
    uint32_t array_;

    uint32_t get(uint32_t idx)
    {
        uint32_t result = 0;
        if (idx < max_size_)
        {
            result = array_ + 0x10 * idx;
            ++*(uint32_t*)(result + 0xC);
        }
        return result;
    }
};

#endif