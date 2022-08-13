#include "charCount.ih"

void CharCount::append(char ch)
{
    updateCapacity();                   // resize capacity if needed
                                        // append ch
    d_charInfo.charPtr[d_charInfo.nCharObj] = Char{ch, 1}; 
    d_charInfo.nCharObj += 1;
}