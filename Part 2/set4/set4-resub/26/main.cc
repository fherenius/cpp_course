#include "base/base.h"
#include "derived/derived.h"
#include <iostream>

using namespace std;

int main()
{
    Base **bp = derivedFactory(10);     // initialize 10 derived objects

    for (size_t idx = 0; idx < 10; ++idx)
        delete bp[idx];                 // delete derived objects
    delete[] bp;
}
