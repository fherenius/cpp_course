#include "numbers.ih"

int &Numbers::operator[](size_t idx)
{
    return element(idx);
}