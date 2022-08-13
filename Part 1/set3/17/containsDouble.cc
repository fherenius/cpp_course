#include "sum.ih"

bool containsDouble(int argc, char **argv)
{
    for (int idx = 1; idx < argc; ++idx) 
    {
        std::string number = argv[argc];
        if (number.find('.') != std::string::npos) 
            return true;
    }
    return false;
}