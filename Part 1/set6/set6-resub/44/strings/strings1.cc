#include "strings.ih"

Strings::Strings()
:
    d_size(0),
    d_capacity(1),
    d_str(rawPointers(d_capacity))
{}
