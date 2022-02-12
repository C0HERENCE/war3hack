#ifndef GLOBAL_VARIABLE_H
#define GLOBAL_VARIABLE_H

#include "table/variable_table.h"
#include "jass.h"
class global_variable
{
public:
    struct array_entry;

    global_variable(const char *name);
    global_variable(variable_node *ptr);
    variable_node *ptr() const;
    OPCODE_VARIABLE_TYPE type() const;
    const char *name() const;
    bool is_array() const;
    bool is_vaild() const;
    operator uint32_t &();
    operator uint32_t const &() const;
    operator array_entry *() const;
    global_variable &operator=(uint32_t v);

    array_entry *entry() const;
    uint32_t array_size() const;
    bool array_vaild(int32_t index) const;
    uint32_t &operator[](int32_t index);
    const uint32_t &operator[](int32_t index) const;

private:
    variable_node *ptr_;
};
#endif