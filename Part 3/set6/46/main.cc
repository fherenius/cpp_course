#include <iostream>
#include "basiccoro/handler.h"
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    for (size_t value: basicCoro(stoul(argv[1]), stoul(argv[2])))
        cout << "Value " << value << '\n';
}