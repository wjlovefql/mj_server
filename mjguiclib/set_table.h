#pragma once

#include "table.h"

class SetTable : public Table {
private:
    static WaveTable* m_instance;
    char*  m_keys;
    int    m_key_num;
    bool   m_collect;

    SetTable();
    ~SetTable();

public:
    void setCollect();

    bool check(int key);

    void dump(char* name);

    void load(char* name);
private:
    int getKey(int number);

    void add(int key);
};
