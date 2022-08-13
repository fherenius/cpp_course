#include "scanner/Scanner.h"


int main()
try
{
    Scanner scanner;

    while (scanner.lex())
        ;
}
catch (...)
{
    return 1;
}


