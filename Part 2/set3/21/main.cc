#include "string.h"
#include <iostream>

using namespace std;

int main()
{
    String str(1, "abc");       

    str.string::insert(1, 1, '@');      // insert char into a String object

                                        // comparison operators
    cout << "equals"     << (str == str) << '\n';   
    cout << "not equals "<< (str != str) << '\n';
    cout << "seq "       << (str <= str) << '\n';
    cout << "smaller "   << (str < str) << '\n';
    cout << "geq "       << (str >= str) << '\n';
    cout << "greater "   << (str > str) << '\n';
}