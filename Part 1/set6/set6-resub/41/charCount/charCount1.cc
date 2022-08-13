#include "charCount.ih"

CharCount::CharCount()
:
    d_capacity(8)
{
    d_charInfo.charPtr = new Char[d_capacity];
}