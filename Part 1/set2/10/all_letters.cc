#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

enum Extended_ascii         // containing the size of the extended ASCII table
{
    SIZE = 256
};

int main()
{
    string letters;
    for (size_t idx = 0; idx < Extended_ascii::SIZE; ++idx) 
    {
        if                  // cast value to character and check if character          
        (                   // is alphabetic
            wchar_t character = static_cast<wchar_t>(idx);
            isalpha(character)
        )
        {
            letters += character;
        }

    }
    cout << letters << '\n';
}