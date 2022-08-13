#include "strings.ih"

Strings &Strings::operator=(Strings const &other)
{
    Strings copy{other};    // copy other to temporary strings
    swap(copy);             // swap copy and this
    return *this;           // return reference
}