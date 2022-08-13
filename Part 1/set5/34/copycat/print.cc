#include "copycat.ih"

void CopyCat::print() const
{
    for (size_t idx = 0; idx != d_size; ++idx) // Every d_data elem to std output
        cout << d_data[idx] << '\n';
}
