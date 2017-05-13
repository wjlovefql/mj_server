#include "table_mgr.h"
#include "set_table.h"

TableMgr::TableMgr()
{
    for(int i=0; i<5; ++i)
    {
        m_check_table[i] = new SetTable;
    }

    for(int i=0; i<5; ++i)
    {
        m_check_eye_table[i] = new SetTable;
    }
 
    for(int i=0; i<5; ++i)
    {
        m_check_feng_table[i] = new SetTable;
    }

    for(int i=0; i<5; ++i)
    {
        m_check_feng_eye_table[i] = new SetTable;
    }
}

TableMgr::~TableMgr()
{
    for(int i=0; i<5; ++i)
    {
        delete m_check_table[i];
    }

    for(int i=0; i<5; ++i)
    {
        delete m_check_eye_table[i];
    }
 
    for(int i=0; i<5; ++i)
    {
        delete m_check_feng_table[i];
    }

    for(int i=0; i<5; ++i)
    {
        delete m_check_feng_eye_table[i];
    }
}

bool TableMgr::set_collect()
{
    for(int i=0; i<5; ++i)
    {
        m_check_table[i]->set_collect();
    }

    for(int i=0; i<5; ++i)
    {
        m_check_eye_table[i]->set_collect();
    }
 
    for(int i=0; i<5; ++i)
    {
        m_check_feng_table[i]->set_collect();
    }

    for(int i=0; i<5; ++i)
    {
        m_check_feng_eye_table[i]->set_collect();
    }
}

bool TableMgr::check(int key, int gui_num, bool eye, bool chi)
{
    Table* tbl = 0;

    if(chi)
    {
        if(eye)
        {
            tbl = m_check_eye_table[gui_num];
        }
        else
        {
            tbl = m_check_table[gui_num];
        }
    }
    else
    {
        if(eye)
        {
            tbl = m_check_feng_eye_table[gui_num];
        }
        else
        {
            tbl = m_check_feng_table[gui_num];
        }
    }

    return tbl->check(key);
}

bool TableMgr::load()
{
    return true;
}

bool TableMgr::dump()
{
    return true;
}

