#include "charCount.ih"

void CharCount::append(char ch)
{
                                               // initialize array for new size
    Char *tmp = new Char[d_charInfo.nCharObj + 1]; 
                                               // copy chars 
    for (size_t idx = 0; idx < d_charInfo.nCharObj; ++idx)
        tmp[idx] = d_charInfo.charPtr[idx];

    tmp[d_charInfo.nCharObj] = Char{ch, 1};    // append ch 
    
    ++d_charInfo.nCharObj;                  // increment char count
    
    delete[] d_charInfo.charPtr;
    d_charInfo.charPtr = tmp;                   // set tmp as new charPtr
}