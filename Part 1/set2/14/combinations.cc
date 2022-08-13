#include <iostream>
#include <string>

using namespace std;						

int main(int argc, char **argv)
{
    ++argv;                             // skip first argument

                                        // iterate over 2 ^ argc binary values
    for (int binaryValue = 0; binaryValue < (1 << (argc - 1)); ++binaryValue)
    {                                   // output format
        cout << binaryValue + 1 << ":";     
        for (int bitPos = 0; bitPos <= argc - 1; ++bitPos)
        {                               // set bit at position bitPos to 1
            size_t bitValue = 0 | (1 << bitPos);
            if (binaryValue & bitValue) // check whether the bitvalue is
                                        // in binary number
                cout << ' ' << argv[bitPos]; 
        }
        cout << "\n";
    }
}