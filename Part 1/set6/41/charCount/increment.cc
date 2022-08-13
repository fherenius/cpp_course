#include "charCount.ih"

void CharCount::increment(char ch)
{
    for (size_t idx = 0; idx < d_charInfo.nCharObj; ++idx)
    {
        if (ch == d_charInfo.charPtr[idx].ch){ // found Char to increment 
            d_charInfo.charPtr[idx].count += 1; 
            break;
        }  
    }
}