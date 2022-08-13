#include "numbers.ih"

int const &Numbers::operator[](size_t idx) const
{
    return element(idx);
}