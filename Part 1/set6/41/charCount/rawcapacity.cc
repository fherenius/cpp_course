#include "charCount.ih"

CharCount::Char *CharCount::rawCapacity(size_t cap)
{
    return new Char[cap];
}