#include "strings.ih"

void Strings::swap(Strings &other)
{
    string *tmp = d_str;
    d_str = other.d_str;
    other.d_str = tmp;

    size_t size = d_size;
    d_size = other.d_size;
    other.d_size = size;

    size_t capacity = d_capacity;
    d_capacity = other.d_capacity;
    other.d_capacity = capacity;
}
