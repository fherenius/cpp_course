#include <iostream>
#include <string>
#include "object/object.h"

using namespace std;
    Object obj;

int main(int argc, char const *argv[])
{

    try
    {
        obj.throwException();

        // obj.hardExit();
    }
    catch(string &e)
    {
        cerr << e << '\n';
    }
}
