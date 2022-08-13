#include "strings.ih"

Strings &Strings::operator=(Strings &&tmp)
{
    swap(tmp);              // swap tmp and this
    return *this;           // return reference
}