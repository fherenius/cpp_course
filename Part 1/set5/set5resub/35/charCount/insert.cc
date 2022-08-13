#include "charCount.ih"

void CharCount::insert(char ch)
{
                                               // initialize array for new size
    Char *tmp = new Char[d_charInfo.nCharObj + 1]; 

    size_t idx = 0;                          // copy chars before ch
    while(idx != d_charInfo.nCharObj && ch > d_charInfo.charPtr[idx].ch)
    {
        tmp[idx] = d_charInfo.charPtr[idx];
        ++idx;
    }

    tmp[idx] = Char{ch, 1};                    // insert ch in tmp
    
    for (; idx < d_charInfo.nCharObj; ++idx)   // copy chars after ch
        tmp[idx + 1] = d_charInfo.charPtr[idx];
    
    d_charInfo.nCharObj += 1;                  // increment char count
        
    delete[] d_charInfo.charPtr;
    d_charInfo.charPtr = tmp;                  // set tmp as new charPtr
}