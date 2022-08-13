#include "base/base.h"
#include "derived/derived.h"
#include "message/message.h"
#include <iostream>

using namespace std;

int main()
{
    Base base;
    Derived derived("Derived message\n");
    Message baseMessage(base);
    Message derMessage(derived);

    baseMessage.show(cout);
    derMessage.show(cout);
}
