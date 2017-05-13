#include <stdio.h>
#include <string.h>
#include "set_table.h"

SetTable::SetTable()
{
    m_collect = false;
}

SetTable::~SetTable()
{
}

void SetTable::set_collect()
{
    m_collect = true;
}

bool SetTable::check(int number)
{
    if(m_collect)
    {
        add(number);
    }

    std::set<int>::iterator it = m_tbl.find(number);
    return it != m_tbl.end();
}

void SetTable::add(int number)
{
    m_tbl.insert(number);
}

void SetTable::dump(char* name)
{
    FILE *fp = fopen(name, "wt+");

    int num = m_tbl.size();

    fwrite(&num, 1, 4, fp);

    for(std::set<int>::iterator it=m_tbl.begin(); it!=m_tbl.end(); ++it)
    {
        int key = *it;
        fwrite(&key, 1, 4, fp);
    }

    fclose(fp);
}

void SetTable::load(char* name)
{
    FILE *fp = fopen(name, "r");

    int num = 0;

    fread(&num, 1, 4, fp);

    for(int i=0; i<num; ++i)
    {
        int key = 0;
        fread(&key, 1, 4, fp);
        m_tbl.insert(key);
    }

    fclose(fp);
}
