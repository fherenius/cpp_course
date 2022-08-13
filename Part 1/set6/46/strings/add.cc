#include "strings.ih"

void Strings::add(string const &next)
{
    if (d_capacity < d_size + 1)           // capacity too small
        resize(d_capacity * 2);            // double the capacity 

    new(d_str + d_size) string{ next };      // store next
    ++d_size;
}
