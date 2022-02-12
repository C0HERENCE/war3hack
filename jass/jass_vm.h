#ifndef JASS_JASS_HASHTABLE_H
#define JASS_JASS_HASHTABLE_H

#include "jass.h"
#include "string/string_hash.h"
#include "table/symbol_table.h"
#include "table/variable_table.h"
#include "table/handle_table.h"
#include "table/string_fasttable.h"
#include "table/native_func_table.h"


struct jass_vm_t
{
    char unk0[0x20];
    opcode *opcode; // 0x20
    char unk1[0x10];
    uint32_t has_sleep; // 0x34
    char unk2[0x2818];
    uint32_t index; //0x2850
    uint32_t unk3;
    symbol_table_t *symbol_table;       //0x2858
    variable_table *global_table; //0x285C
    uint32_t unk4;
    uint32_t unk5;
    uint32_t *stackframe; //0x2868
    uint32_t unk6;
    uint32_t unk7;
    string_fasttable *string_table; //0x2874
    char unk8[0x10];
    uint32_t *code_table; //0x2888
    char unk9[0x14];
    uintptr_t set_handle_reference; //0x28A0
    handle_table_t **handle_table;  //0x28A4
};

typedef int(__fastcall *_GetInstance)(int index);
extern _GetInstance GetInstance;

jass_vm_t *get_jass_thread();
jass_vm_t *get_jass_vm(int index = 1);
native_func_table *get_native_function_hashtable();

#endif