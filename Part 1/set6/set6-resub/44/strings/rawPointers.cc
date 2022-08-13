#include "strings.ih"

string **Strings::rawPointers(size_t n)
{
    return new string*[n];
}