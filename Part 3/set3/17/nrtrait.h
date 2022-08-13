//JB: 0
#ifndef INCLUDED_NRTRAIT_H
#define INCLUDED_NRTRAIT_H

#include <cstddef>
#include <cmath> // JB: Don't use these C functions. Are they even constexpr?

template <size_t number>
struct NrTrait
{
    //JB: Why use static const if you can use enum?
    //JB: (No guarantee that static const is evaluated compile-time.)
    static size_t const value = number;
    static bool const even = ! (number % 2);
    static bool const by3 = ! (number % 3);
    static size_t const width = log10(number) + 1;

};



#endif

