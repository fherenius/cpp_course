#include "strings.ih"

void Strings::add(string const &next)
{
    if (d_capacity < d_size + 1)           // capacity too small
        reserve(d_capacity * 2);            // double the capacity 

    d_str[d_size] = new string(next);                 // store next
    ++d_size;
}
