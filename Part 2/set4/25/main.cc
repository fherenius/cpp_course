#include "base.h"
#include "derived.h"
#include "message.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Base base;
    Derived derived("Derived message\n");
    Message baseMessage(base);
    Message derMessage(derived);

    baseMessage.show(cout);
    derMessage.show(cout);
}
