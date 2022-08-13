#include "numbers.ih"

Numbers::Numbers(Numbers  &&other)
:
    d_len(other.d_len),
    d_int(other.d_int)
{
    other.d_len = 0;  
    other.d_int = 0;
}