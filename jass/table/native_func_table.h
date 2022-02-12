#ifndef JASS_NATIVE_FUNC_TABLE_H
#define JASS_NATIVE_FUNC_TABLE_H

#include <cstdint>
#include "table.h"

struct virtual_func_table
{
    uint32_t vfn_; // 虚表
};

// native_func_node < native_func_table
struct native_func_node : public virtual_func_table, public node
{
    uint32_t func_address_;  // 函数地址
    uint32_t param_num_;     // 参数个数
    const char *param_list_; // 参数列表
};

struct native_func_table
{
    table<native_func_node> table_;

    native_func_node *find(const char *str)
    {
        return table_.find(str);
    }
};

#endif