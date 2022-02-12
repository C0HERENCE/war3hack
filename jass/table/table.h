#ifndef JASS_TABLE_H
#define JASS_TABLE_H

#include <cstdint>
#include <cstring>
// node_2 < node_1 < node < entry < table <table::iterator
struct node;
struct node_2 // 左边
{
    node_2 *lft_;
    node *rht_;
    const char *str_;
};

struct node_1 // 下一层
{
    node_1 *next_;
    node *prev_;
    node_2 *lft_;
    node *rht_;
    const char *str_;
};

struct node
{
    uint32_t hash_; // 哈希值
    node_1 *next_;  // 下一层
    node *prev_;    // 上一层
    node_2 *lft_;   // 左边
    node *rht_;     // 右边
    uint32_t key;   // key值
    bool is_vaild() const
    {
        return ((intptr_t)this > 0x10000);
    }
};


template <class Node = node>
struct entry
{
    uint32_t step;
    node_1 *tail;
    Node *head;

    node *convert(Node *ptr) const
    {
        return (node *)((uintptr_t)ptr + step - 4);
    }
};


template <class Node = node>
struct table
{
    uint32_t unk0;
    uint32_t step;
    uint32_t tail;
    Node *head;
    uint32_t unk4;
    uint32_t unk5;
    uint32_t unk6;
    entry<Node> *buckets;
    uint32_t unk8;
    uint32_t mask;

    class iterator;
    class iterator_v1;

    Node *find(uint32_t hash)
    {
        Node *fnode_ptr = nullptr;

        if (mask == 0xFFFFFFFF)
            return nullptr;

        fnode_ptr = buckets[hash & mask].head;

        if (!fnode_ptr->is_vaild())
            return nullptr;

        for (;;)
        {
            if (fnode_ptr->hash_ == hash)
                return fnode_ptr;
            fnode_ptr = (Node *)(uintptr_t)(fnode_ptr->prev_);

            if (!fnode_ptr->is_vaild())
                return nullptr;
        }
    }
    Node *find(const char *str)
    {
        uint32_t hash;
        Node *fnode_ptr = nullptr;

        if (mask == 0xFFFFFFFF)
            return nullptr;

        hash = string_hash(str);
        fnode_ptr = buckets[hash & mask].head;

        if (!fnode_ptr->is_vaild())
            return nullptr;

        for (;;)
        {
            if (fnode_ptr->hash_ == hash)
            {
                if ((const char *)fnode_ptr->key == str)
                    return fnode_ptr;

                if (0 == strcmp((const char *)fnode_ptr->key, str))
                    return fnode_ptr;
            }
            fnode_ptr = (Node *)(uintptr_t)(fnode_ptr->prev_);

            if (!fnode_ptr->is_vaild())
                return nullptr;
        }
    }
    iterator begin() const
    {
        return iterator(this);
    }

    iterator end() const
    {
        return iterator();
    }
};

template <class Node>
class table<Node>::iterator
{
public:
    typedef Node value_type;
    typedef value_type &reference;
    typedef value_type *pointer;

public:
    iterator()
        : ptr_(nullptr), current_(nullptr)
    {
    }

    explicit iterator(const table<Node> *ptr)
        : ptr_(ptr), current_(ptr->head)
    {
        if (!current_->is_vaild())
        {
            current_ = nullptr;
        }
    }

    ~iterator()
    {
    }

    reference operator*() const
    {
        return *current_;
    }

    pointer operator->() const
    {
        return current_;
    }

    iterator operator++(int)
    {
        auto result = *this;
        ++(*this);
        return result;
    }

    iterator &operator++()
    {
        current_ = (Node *)((uint32_t *)current_)[ptr_->step / 4 + 1];
        if (!current_->is_vaild())
        {
            current_ = nullptr;
        }
        return *this;
    }

    bool operator==(const iterator &other) const
    {
        return current_ == other.current_;
    }

    bool operator!=(const iterator &other) const
    {
        return !operator==(other);
    }

private:
    const table<Node> *ptr_;
    Node *current_;
};

#endif