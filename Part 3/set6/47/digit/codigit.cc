#include "digit.ih"

Digit coDigit()
{
    char ch;
    while (cin.get(ch))
    {
        if (isalpha(ch))
        {
            cout << "at `" << ch << "' from digit to letter\n";
            co_await g_letter;
        }
        else if (isdigit(ch))
            cout << "at `" << ch << "' remain in digit\n";
        else
        {
            cout << "at char #" << static_cast<int>(ch) <<
                    ": from digit to start\n";
            co_await g_start;
        }
    }

    co_await g_done;
}
