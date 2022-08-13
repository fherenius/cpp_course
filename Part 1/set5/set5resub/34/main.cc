#include "copycat/copycat.h"
#include <iostream>

extern char **environ;

int main(int argc, char **argv)
{
    CopyCat cat1;               // use 1st constructor, calls 3rd constructor
    cat1.print(std::cout);

    CopyCat cat2(argc, argv);   // use 2nd constructor for command line args
    cat2.print(std::cout);

    CopyCat cat3(environ);      // use 3rd constructor explicitly with environ
    cat3.print(std::cout);
    
}