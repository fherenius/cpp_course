#include "numbers.ih"

int &Numbers::operator[](size_t idx) const
{
    return element(idx);
}