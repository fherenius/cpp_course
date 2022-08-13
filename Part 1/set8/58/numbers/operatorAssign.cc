#include "numbers.ih"

Numbers &Numbers::operator=(Numbers const &other)
{
    Numbers copy{other};    // copy other to temporary strings
    swap(copy);             // swap copy and this
    return *this;           // return reference
}