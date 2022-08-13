#include "charCount.ih"

void CharCount::checkCapacity()
{
    if (d_charInfo.nCharObj + 1 > d_capacity)
        enlarge();
}