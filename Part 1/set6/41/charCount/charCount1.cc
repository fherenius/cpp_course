#include "charCount.ih"

CharCount::CharCount()
:
    d_capacity(8)
{
    d_charInfo.charPtr = rawCapacity(d_capacity);
}