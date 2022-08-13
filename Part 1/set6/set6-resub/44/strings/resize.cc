#include "strings.ih"

void Strings::resize(size_t n)
{
    if (n > d_size)
    {
        if (n > d_capacity)
            reserve(n);              // reserve memory 

        for (size_t idx = d_size; idx < n; ++idx)
            d_str[idx] = new string; // fill memory with empty string
        
        d_size = n;                  // update size
    }
    else if (n < d_size)             // n is smaller than size
    {
        for (size_t idx = d_capacity - 1; idx >= n; --idx)
            delete d_str[idx];       // delete until n elements left
        d_size = n;                  // update size
    }
}