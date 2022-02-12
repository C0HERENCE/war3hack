#ifndef JASS_JASS_H
#define JASS_JASS_H
#include <cstdint>
enum OPCODE_VARIABLE_TYPE
{
    OPCODE_VARIABLE_NOTHING = 0,   // "nothing"
    OPCODE_VARIABLE_UNKNOWN,       // "unknown"
    OPCODE_VARIABLE_NULL,          // "null"
    OPCODE_VARIABLE_CODE,          // "code"
    OPCODE_VARIABLE_INTEGER,       // "integer"
    OPCODE_VARIABLE_REAL,          // "real"
    OPCODE_VARIABLE_STRING,        // "string"
    OPCODE_VARIABLE_HANDLE,        // "handle"
    OPCODE_VARIABLE_BOOLEAN,       // "boolean"
    OPCODE_VARIABLE_INTEGER_ARRAY, // "integer array"
    OPCODE_VARIABLE_REAL_ARRAY,    // "real array"
    OPCODE_VARIABLE_STRING_ARRAY,  // "string array"
    OPCODE_VARIABLE_HANDLE_ARRAY,  // "handle array"
    OPCODE_VARIABLE_BOOLEAN_ARRAY, // "boolean array"
};
struct opcode
{
    uint8_t r3;
    uint8_t r2;
    uint8_t r1;
    uint8_t op;
    uint32_t arg;
};
#endif