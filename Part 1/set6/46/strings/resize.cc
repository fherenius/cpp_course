#include "strings.ih"

void Strings::resize(size_t newSize)
{
    if (newSize > d_size) 
        reserve(newSize);              // update capacity to new      
    else if (newSize < d_size)         // n is smaller than size
    {
        for (size_t idx = d_size - 1; idx != newSize; --idx)
            d_str[idx].~string();
        d_size = newSize;              // update size
    }        
    
                
}