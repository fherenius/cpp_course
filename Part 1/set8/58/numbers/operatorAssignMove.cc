#include "numbers.ih"

Numbers &Numbers::operator=(Numbers &&tmp)
{
    swap(tmp);             // swap copy and this
    return *this;           // return reference
}