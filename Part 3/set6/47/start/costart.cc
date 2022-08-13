#include "start.ih"
//coro
Start coStart()
{
    char ch; // Var to store char in
    while (cin.get(ch)) // Get char from stdin
    {
        if (isalpha(ch)) // If letter
        {
            cout << "at `" << ch << "' from start to letter\n";
            co_await g_letter; // Run letter coroutine
        }
        else if (isdigit(ch)) // If digit
        {
            cout << "at `" << ch << "' from start to digit\n";
            co_await g_digit; // Run digit coroutine
        }
        else // if other
            cout << "at char #" << static_cast<int>(ch) <<
                    ": remain in start\n";
    }
    co_await g_done; // once EOF run done coroutine
}
//=
