#include "charCount.ih"

void CharCount::enlarge()
{
    d_capacity *= 2;                        // double the capacity
    Char *tmp = rawCapacity(d_capacity);

    for (size_t idx; idx != d_charInfo.nCharObj; ++idx)
        tmp[idx] = d_charInfo.charPtr[idx]; // copy Char objects

    delete[] d_charInfo.charPtr;            // return old Chars        
    d_charInfo.charPtr = tmp;               // set tmp as charPtr
}