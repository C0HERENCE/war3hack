#ifndef JASS_REVERSE_TABLE_H
#define JASS_REVERSE_TABLE_H

#include "table.h"

// reverse_node < reverse_table < handle_table
struct reverse_node : public node
{
    uint32_t value;
};

struct reverse_table
{
    typedef table<reverse_node> table_t;
    typedef table_t::iterator iterator;

    uint32_t unk0_;
    uint32_t size;
    reverse_node **node_array_;
    uint32_t unk3_;
    table_t table_;

    iterator begin()
    {
        return iterator(&table_);
    }

    iterator end()
    {
        return iterator();
    }

    reverse_node *at(uint32_t index)
    {
        return node_array_[index];
    }

    reverse_node *find(uint32_t hash)
    {
        return table_.find(hash);
    }

    reverse_node *find(const char *str)
    {
        return table_.find(str);
    }
};

#endif