#include <string.h>
#include "hulib.h"
#include "wave_table.h"
#include "wave_eye_table.h"

bool HuLib::get_hu_info(char* const hand_cards, Wave* const waves, char self_card, char other_card)
{
    char hand_cards_tmp[34];
    memcpy(hand_cards_tmp, hand_cards, 34);

    HuInfo info;

    if(!check_zi(hand_cards_tmp, info))
    {
        return false;
    }
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
    int c = 0;
    for(int i=0;i<n;i++)
    {
        c = c + cards[i];
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

        return check_wave_and_eye(cards, n);
    }

    return check_wave(cards, n);
}

bool HuLib::check_wave(char* const cards, int n)
{
    int num = 0;
    for(int i=0; i<n; ++i)
    {
        num = num * 10 + cards[i];
    }

    return WaveTable::getInstance()->check(num);
}

bool HuLib::check_wave_and_eye(char* const cards, int n)
{
    int num = 0;
    for(int i=0; i<n; ++i)
    {
        num = num * 10 + cards[i];
    }

    return WaveEyeTable::getInstance()->check(num);
}
