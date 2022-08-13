#include <iostream>
#include "chars.h"


using namespace std;


int main()
{
    cout << Chars<'h', 'e', 'l', 'l', 'o'>{} << '\n'
         << Chars<>() << '\n';
}
