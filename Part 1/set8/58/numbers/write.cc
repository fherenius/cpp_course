#include "numbers.ih"

void Numbers::write(ostream &out)
{
    for (size_t idx = 0; idx < d_len; ++idx)
        out << d_int[idx] << " ";   
    out << '\n';
}