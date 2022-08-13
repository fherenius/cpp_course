#include "letter.ih"

Letter coLetter()
{
    char ch;
    while (cin.get(ch))
    {
        if (isalpha(ch))
            cout << "at `" << ch << "' remain in letter\n";
        else if (isdigit(ch))
        {
            cout << "at `" << ch << "' from letter to digit\n";
            co_await g_digit;
        }
        else
        {
            cout << "at char #" << static_cast<int>(ch) <<
                    ": from letter to start\n";
            co_await g_start;
        }
    }
    co_await g_done;
}
