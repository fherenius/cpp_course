#include "charCount.ih"

void CharCount::insert(char ch)
{
    d_charInfo.nCharObj += 1;                  // increment char count

    Char *tmp = new Char[d_charInfo.nCharObj]; // initialize array for new size

    for (size_t idx = 0, inserted = 0; idx < d_charInfo.nCharObj - 1; ++idx)
    {                                          // insert char at idx
        if (ch < d_charInfo.charPtr[idx].ch && !inserted)
        {
            tmp[idx].ch = ch;
            tmp[idx].count = 1;
            inserted = 1;
        }                                      // copy Chars to temp 
        tmp[idx + inserted].ch = d_charInfo.charPtr[idx].ch;
        tmp[idx + inserted].count = d_charInfo.charPtr[idx].count;
    }

    d_charInfo.charPtr = tmp;                  // set tmp as new charPtr
}