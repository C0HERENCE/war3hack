#ifndef JASS_HANDLE_TABLE_H
#define JASS_HANDLE_TABLE_H

struct handle_table_t
{
    char unk[0x194];
    reverse_table table; // 0x194
};

#endif