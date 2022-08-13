#include "data.ih"

void Data::swap(Data &other, Type current, Type next)
{
    (this->*s_swap[current][next]) (other);
}
