#include "handler.h"
    

    // The basic coroutine that returns the next integer
    // for every call starting with the next value given as argument.
Handler basicCoro(size_t value, size_t iterations)
{
    while (true)
        co_yield ++value;       // Initial value is already set so prefix incr
}
