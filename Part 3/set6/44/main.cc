#include <iostream>
#include "handlercoro/handler.h" // JB: First, against include omissions.

using namespace std;

int main(int argc, char const **argv)
{
    Handler handler = handlerCoro(argv[1]);
    
    int value;
    while (handler.next(&value))
        cout << value << '\n';
}
