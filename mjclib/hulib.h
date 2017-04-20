#pragma once

struct Wave
{
};

struct HuInfo
{
    bool eye;
    HuInfo()
    {
        eye = false;
    }
};

class HuLib
{
    static bool get_hu_info(char* const hand_cards, Wave* const waves, char self_card, char other_card);
    static bool check_zi(char* const hand_cards, HuInfo& info);
};
