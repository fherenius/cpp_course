#include "derived.ih"

Base **derivedFactory(size_t size)
{
    Base **bp = new Base *[size];
    for (size_t idx = 0; idx < size; ++idx)
        bp[idx] = new Derived;      // Initialize bp with derived objects

    return bp;
}