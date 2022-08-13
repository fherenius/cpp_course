#include "numbers.ih"

int &Numbers::at(size_t idx)
{
    if (idx >= d_len)
    {
        cout << "Error: index out of range!\n";
    }
    return d_int[idx];
}