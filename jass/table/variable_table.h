#ifndef JASS_VARIABLE_TABLE_H
#define JASS_VARIABLE_TABLE_H

#include "table.h"
// variable_node < variable_table
struct variable_node : public node
{
    uint32_t array_;
    uint32_t type_;
    uint32_t value_;
};

struct variable_table
{
    typedef table<variable_node> table_t;
    typedef table_t::iterator iterator;
    table_t table_;

    iterator begin() const
    {
        return iterator(&table_);
    }

    iterator end() const
    {
        return iterator();
    }

    variable_node *find(const char *str)
    {
        return table_.find(str);
    }
};

#endif