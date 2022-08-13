#include "handler.h"
    

    // The basic coroutine that returns the next integer
    // for every call starting with the value given as argument.
Handler basicCoro(size_t value)
{
    
    while (true)
        co_yield value++;

}
