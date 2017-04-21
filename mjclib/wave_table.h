#pragma once

class WaveTable {
private:
    static WaveTable* m_instance;
public:
    static WaveTable* getInstance();

    bool check(int key);

    void add();

    void dump(char* name);
}
