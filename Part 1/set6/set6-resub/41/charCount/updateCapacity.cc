#include "charCount.ih"

void CharCount::updateCapacity()
{
    if (d_charInfo.nCharObj + 1 > d_capacity)
        enlarge();
}