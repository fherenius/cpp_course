#include "numbers.ih"

ostream &operator<<(ostream &out, Numbers const &num)
{
    for(size_t idx = 0; idx != num.size(); ++idx)
        out << num[idx] << ' ';     // insert into ostream 
    return out;
}