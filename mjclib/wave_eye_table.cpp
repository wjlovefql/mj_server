#include <stdio.h>
#include <string.h>
#include "wave_eye_table.h"

WaveEyeTable* WaveEyeTable::m_instance = NULL;

WaveEyeTable::WaveEyeTable()
{
    m_collect = false;
    m_key_num = 1 << 18;
    m_keys = new bool[1<<18];
    memset(m_keys, 0, m_key_num/8);
}

WaveEyeTable::~WaveEyeTable()
{
    delete[] m_keys;
}

WaveEyeTable* WaveEyeTable::getInstance()
{
    if(!m_instance)
    {
        m_instance = new WaveEyeTable;
    }
    return m_instance;
}

int WaveEyeTable::getKey(int number)
{
    int bits = 0x0000;
    int shift = 0;
    while(number > 0)
    {
        int n = (number % 10) - 1;
        n = n << shift;
        shift = shift + 2;
        bits = bits | n;
        number = number/10;
    }

    return bits;
}

void WaveEyeTable::setCollect()
{
    m_collect = true;
}

bool WaveEyeTable::check(int number)
{
    int key = getKey(number);

    if(m_collect)
    {
        add(number);
    }

    return m_keys[key];
}

void WaveEyeTable::add(int number)
{
    int key = getKey(number);
    m_keys[key] = true;
}

void WaveEyeTable::dump(char* name)
{
    FILE *fp = fopen(name, "wt+");

    fwrite(m_keys, sizeof(bool), m_key_num, fp);

    fclose(fp);
}

void WaveEyeTable::load(char* name)
{
    FILE *fp = fopen(name, "r");

    fread(m_keys, sizeof(bool), m_key_num, fp);

    fclose(fp);
}
