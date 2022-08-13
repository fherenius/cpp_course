#include "strings/strings.h"
#include <iostream>

using namespace std;

extern char **environ;

int main()
{
    Strings strings{cin};

    strings.resize(100);

    for (size_t idx = 0, end = strings.size(); idx != end; ++idx)
        cout << "line " << idx + 1 << ": " << strings.at(idx) << '\n';
}