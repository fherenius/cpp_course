#include "main.ih"

void showChar(CharCount::CharInfo charInfo)
{
    for(size_t idx = 0; idx < charInfo.nCharObj; ++idx) // loop over objects
    {
        cout << "char ";
        switch (charInfo.charPtr[idx].ch)
        {
            case '\n':                                  // print special case
                cout << "'\\n'";
                break;
            case '\t':
                cout << "'\\t'";
                break;
            default:                                    // default case
                if (isprint(charInfo.charPtr[idx].ch))  // printable chars
                    cout << "'" << charInfo.charPtr[idx].ch << "'";
                else                                    // non-printable chars
                    cout << -1 * charInfo.charPtr[idx].ch + 127;        
                break;
        } 
        cout << ": " << charInfo.charPtr[idx].count << " times\n";
    }
}