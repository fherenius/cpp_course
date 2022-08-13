#include "strings.ih"

void Strings::reserve(size_t n)
{
    if (n <= d_size)
        return;

    string **tmp = rawPointers(n);             // allocate memory for n strings
                                               
                                               // if n smaller than d_size
                                               // only copy first n strings
    for (size_t idx = 0; idx < d_size && idx < n; ++idx)     
        tmp[idx] = d_str[idx];                 // copy strings to tmp
    
    d_capacity = n;                            // update capacity
    
    delete[] d_str;                            // return old pointers
    d_str = tmp;                           
}