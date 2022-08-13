#include "done.ih"

//coro
Done coDone()
{
    cout << "at EOF: done\n";
    co_return;
}
//=
