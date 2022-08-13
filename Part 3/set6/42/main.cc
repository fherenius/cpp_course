#include "basiccoro/handler.h"

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char **argv)
{
    Handler h1 = basicCoro(stoul(argv[1]));
    Handler h2 = basicCoro(stoul(argv[2]));

    for (size_t begin = 0, end = stoul(argv[3]); begin != end; ++begin)
        cout << "Value from h1: " << h1.next() << ", "
                "value from h2: " << h2.next() << '\n';

}

