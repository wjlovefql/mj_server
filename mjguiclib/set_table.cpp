#include <stdio.h>
#include <string.h>
#include "wave_table.h"

SetTable::SetTable()
{
    m_collect = false;
    m_key_num = 1 << 27;
    m_keys = new char[m_key_num];
    memset(m_keys, 0, m_key_num);
}

SetTable::~SetTable()
{
    delete[] m_keys;
}

int SetTable::getKey(int number)
{
    int bits = 0x0000;
    int shift = 0;
    while(number > 0)
    {
        int n = (number % 10);
        n = n << shift;
        shift = shift + 3;
        bits = bits | n;
        number = number/10;
    }

    return bits;
}

void SetTable::setCollect()
{
    m_collect = true;
}
bool SetTable::check(int number)
{
    int key = getKey(number);

    if(m_collect)
    {
        add(number);
    }

    return m_keys[key] == 1;
}

void SetTable::add(int number)
{
    int key = getKey(number);
    m_keys[key] = 1;
}

void SetTable::dump(char* name)
{
    FILE *fp = fopen(name, "wt+");

    fwrite(m_keys, 1, m_key_num, fp);

    fclose(fp);
}

void SetTable::load(char* name)
{
    FILE *fp = fopen(name, "r");

    fread(m_keys, 1, m_key_num, fp);

    fclose(fp);
}
