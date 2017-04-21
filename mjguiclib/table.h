#pragma once

class Table {
private:
    Table(){}
    ~Table(){}

public:
    virtual void setCollect() = NULL;

    virtual bool check(int key) = NULL;

    virtual void dump(char* name) = NULL;

    virtual void load(char* name) = NULL;
private:
    virtual int getKey(int number) = NULL;

    virtual void add(int key) = NULL;
}
