#include "numbers.ih"

Numbers::Numbers(size_t count, int value)
:
    d_len(count),
    d_int(new int[count])
{
    for (size_t idx = 0; idx < count; idx++)
        d_int[idx] = value;   
}