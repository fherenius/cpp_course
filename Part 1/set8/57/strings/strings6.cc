#include "strings.ih"

Strings::Strings(Strings &&tmp)
: 
    d_size(tmp.d_size),
    d_capacity(tmp.d_capacity),
    d_str( std::move(tmp.d_str) )
{
    tmp.d_capacity = 0;
    tmp.d_size = 0;
    tmp.d_str = 0;
}