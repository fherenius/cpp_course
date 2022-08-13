#include <iostream>

using namespace std;

int main()
{
    size_t value;    

    // read value
    cin >> value;   

    // an even value is divisible by two
    cout << (value % 2 ? "odd" : "even") << '\n';    

    // if lowest bit is 1, number is odd
    cout << (value & 1 ? "odd" : "even") << '\n';                               

    // integer division rounds down, while float multiplication doens't
    // therefore odd numbers divided by two arent equal to the number * 0.5
    cout << ((value / 2 - value * 0.5) == 0 ? "even" : "odd") << '\n';  

    // if the lowest bit is 1, number is odd
    // therfore OR with 1 would yield the same number if odd 
    cout << ((value | 1) == value ? "odd" : "even") << '\n';                    

    // odd numbers only change last bit when 1 is added 
    // therefore xor equals 1
    cout << ((value ^ (value + 1)) == 1 ? "even" : "odd") << '\n';              

    // only information for odd numbers is lost
    // when last bit is lost
    cout << ((value >> 1) << 1 == value ? "even" : "odd") << '\n';              
}
