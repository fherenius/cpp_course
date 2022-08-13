#include "main.ih"

void showChar(CharCount::Char charObj)
{
    cout << "char ";
    switch (charObj.ch)
    {
        case '\n':                                  // print special case
            cout << "'\\n'";
            break;
        case '\t':
            cout << "'\\t'";
            break;
        default:                                    // default case
            showDefaultChar(charObj.ch);
            break;
    } 
    cout << ": " << charObj.count << " times\n";
} 
