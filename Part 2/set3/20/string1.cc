#include "string.ih"

String::String(size_t count, string const &str)
{
    for (size_t idx = 0; idx < count; ++idx)
        append(str);
}