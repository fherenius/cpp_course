#include "handler.h"

#include <fstream>

using namespace std;

    // The basic coroutine that returns the next integer
    // for every call starting with the value given as argument.
Handler handlerCoro(char const *fileName)
{
    ifstream fin{ fileName };   // Open the file

    //JB: :-) although you might want to throw?
    if (!fin)                   // Return if the file is not valid
        co_return;

    int prev = 0;
    int current;
    
    while (fin >> current)
    {
        co_yield current + prev;
        prev = current;
    }

    co_return;                  // Return sets the d_valid of state to false
}
