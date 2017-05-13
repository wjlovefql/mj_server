#pragma once

class Table {
public:
    Table(){}
    virtual ~Table(){}

public:
    virtual void set_collect()=0;

    virtual bool check(int key)=0;

    virtual void dump(char* name)=0;

    virtual void load(char* name)=0;
};
