#pragma once

#include "table.h"
#include <set>

class SetTable : public Table {
private:
    std::set<int> m_tbl;
    bool m_collect;

public:
    SetTable();
    virtual ~SetTable();

public:
    void set_collect();

    bool check(int key);

    void dump(char* name);

    void load(char* name);
private:
    void add(int key);
};
