#include "charCount.ih"

CharCount::Action CharCount::locate(char ch)
{

    if (d_charInfo.charPtr == 0     // no char saved || char > last element
        || ch > d_charInfo.charPtr[d_charInfo.nCharObj - 1].ch)
        return APPEND;
    
    for (size_t idx = 0; idx < d_charInfo.nCharObj; ++idx)
    {                               // char already saved
        if (ch == d_charInfo.charPtr[idx].ch)   
            return INC;
    }
    return INSERT;                  // char < last element and not saved

}