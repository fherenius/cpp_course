#include "charCount.ih"

void CharCount::append(char ch)
{
    d_charInfo.nCharObj += 1;                  // increment char count

    Char *tmp = new Char[d_charInfo.nCharObj]; // initialize array for new size

    for (size_t idx = 0; idx < d_charInfo.nCharObj - 1; ++idx)
    {
        tmp[idx].ch = d_charInfo.charPtr[idx].ch;
        tmp[idx].count = d_charInfo.charPtr[idx].count;
    }

    tmp[d_charInfo.nCharObj - 1].ch = ch;
    tmp[d_charInfo.nCharObj - 1].count = 1;
    
    
    d_charInfo.charPtr = tmp;
}