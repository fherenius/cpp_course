#include "strings.ih"

Strings::~Strings()
{
    for (size_t idx = 0; idx != d_size; ++idx) 
        delete d_str[idx];                      // return strings
    delete[] d_str;                             // return string pointers
}
