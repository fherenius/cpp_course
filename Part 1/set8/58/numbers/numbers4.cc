#include "numbers.ih"

Numbers::Numbers(Numbers const &other)
:
    d_len(other.d_len),
    d_int(new int[d_len])
{
    for (size_t idx = 0; idx < d_len; idx++)
        d_int[idx] = other.d_int[idx];   
}