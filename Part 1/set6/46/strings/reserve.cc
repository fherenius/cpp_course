#include "strings.ih"

void Strings::reserve(size_t newCap)
{
    if (newCap <= d_capacity)
        return;

    string *tmp = rawStrings(newCap);           // allocate raw memory
                                               
                                               // if n smaller than d_size
                                               // only copy first n strings
    for (size_t idx = 0; idx < d_size && idx < newCap; ++idx)     
        new (tmp + idx) string{ d_str[idx] };  // copy strings to tmp
    
    d_capacity = newCap;                       // update capacity
    
    destroy();                                 // return old memory
    d_str = tmp;                           
}