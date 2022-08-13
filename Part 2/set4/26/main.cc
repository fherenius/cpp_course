#include "base.h"
#include "derived.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Base **bp = derivedFactory(10);

    for (size_t idx = 0; idx < 10; ++idx)
        delete bp[idx];
    delete[] bp;
}
