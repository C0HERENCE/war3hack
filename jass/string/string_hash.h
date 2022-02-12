#ifndef STRING_HASH
#define STRING_HASH

#include <cstdint>

uint32_t string_hash_ex(const char* str, size_t size, uint32_t prev);

uint32_t string_hash(const char* str);

#endif