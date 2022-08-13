#include "copycat.ih"

void CopyCat::print(ostream &out) const
{
    for (size_t idx = 0; idx != d_size; ++idx) 
        out << d_data[idx] << '\n';   // insert every d_data elem to std output
}
