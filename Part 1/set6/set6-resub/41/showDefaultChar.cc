#include "main.ih"

void showDefaultChar(char ch)                       // helper function
{
    if (isprint(ch))                                // printable chars
        cout << "'" << ch << "'";
    else                                            // non-printable chars
        cout << static_cast<int>(ch); 
}