#include <stdio.h>
#include <string.h>
#include "hulib.h"
#include "wave_table.h"
#include "wave_eye_table.h"

//#define LOG printf
#define LOG log

void log(char*, ...)
{
}

struct ProbabilityItem
{
    bool eye;
    int gui_num;
    ProbabilityItem(bool eye, int gui_num)
    {
        this->eye = eye;
        this->gui_num = gui_num;
    }
}

struct ProbabilityItemTable
{
    ProbabilityItem m[4][5];
    int array_num;
    int m_num[4];
}


bool HuLib::get_hu_info(char* const hand_cards, Wave* const waves, char self_card, char other_card, int gui_index)
{
    char hand_cards_tmp[34];
    memcpy(hand_cards_tmp, hand_cards, 34);

    if(self_card)
    {

    }
    else if(other_card)
    {

    }

    int gui_num = hand_cards_tmp[gui_index];
    hand_cards_tmp[gui_index] = 0;

}

void HuLib::split_info(char* const cards, int gui_num)
{
}

bool HuLib::check_zi(char* const hand_cards, HuInfo& info)
{
    for(int i = 27; i<34; ++i)
    {
        int n = hand_cards[i];
        if(n == 1 || n == 4)
        {
            return false;
        }

        if(n == 2)
        {
            if(info.eye)
            {
                return false;
            }

            info.eye = true;
        }
    }

    return true;
}

bool HuLib::check_chi(char* const hand_cards, HuInfo& info, int min)
{
    char tbl[9];
    int n = 0;

    for(int i=min; i<min+9; ++i)
    {
        int c = hand_cards[i];
        if(c > 0)
        {
            tbl[n++] = c;
        }
        else
        {
            if(n==0) continue;

            if(!check_sub(tbl, n, info))
            {
                return false;
            }

            n = 0;
        }
    }

    return true;
}

bool HuLib::check_sub(char* const cards, int n, HuInfo& info)
{
    LOG("wave:  ");
    for(int i=0;i<n;++i)
    {
        LOG("%d ", cards[i]);
    }
    LOG("\n");

    int c = 0;
    int number = 0;
    for(int i=0;i<n;i++)
    {
        c = c + cards[i];
        number = number * 10 + cards[i];
    }

    int yu = c % 3;

    if(yu == 1)
    {
        return false;
    }
    else if(yu == 2)
    {
        if(info.eye) return false;

        info.eye = true;

        return check_wave_and_eye(number);
    }

    return check_wave(number);
}

bool HuLib::check_wave(int number)
{
    return WaveTable::getInstance()->check(number);
}

bool HuLib::check_wave_and_eye(int number)
{
    return WaveEyeTable::getInstance()->check(number);
}

bool HuLib::check_7dui(char* const cards)
{
    int c = 0;
    for(int i=0;i<34;++i)
    {
        if(cards[i] % 2 != 0) return false;
        c += cards[i];
    }

    if(c != 34) return false;

    return true;
}

bool HuLib::check_pengpeng(char* const cards, Wave* const waves, char self_card, char other_card)
{
    bool eye = false;

    for(int i=0;i<34;++i)
    {
        int c = cards[i];
        if(c == 1 || c == 4) return false;

        if(c == 2)
        {
            if(eye) return false;
            eye = true;
        }
    }

    // 检查吃碰杠的牌

    return true;
}

