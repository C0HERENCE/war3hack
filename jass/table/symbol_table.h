#ifndef JASS_TABLE_SYMBOL_TABLE_H
#define JASS_TABLE_SYMBOL_TABLE_H
#include "reverse_table.h"
struct symbol_table_t {
		uint32_t unk0;
		uint32_t unk1;
		reverse_table* string_table;
};
#endif