#include "charCount.ih"

void CharCount::insert(char ch)
{
    updateCapacity();

    size_t idx = d_charInfo.nCharObj - 1;  
    while(idx != 0 && ch < d_charInfo.charPtr[idx].ch)
    {
        d_charInfo.charPtr[idx + 1] = d_charInfo.charPtr[idx];
        --idx;
    }
    d_charInfo.charPtr[idx + 1] = Char{ch, 1};     // insert ch
    d_charInfo.nCharObj += 1;
}