#include "strings.ih"
//static
string *Strings::rawStrings(size_t newCap)
{
    return static_cast<string *>
    (
        operator new(newCap * sizeof(string))
    );
    
}
