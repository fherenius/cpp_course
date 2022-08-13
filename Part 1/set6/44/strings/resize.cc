#include "strings.ih"

void Strings::resize(size_t n)
{
    if (n > d_size) 
        reserve(n);              // update capacity to n      
    else if (n < d_size)         // n is smaller than size
    {
        for (size_t idx = d_capacity - 1; idx >= n; --idx)
            delete d_str[idx];   // delete until n elements left
        d_size = n;              // update size
        d_capacity = n;          // update capacity
    }                        
}