#include "main.ih"
                    // Function to sum integers.
int sum(int argc, char *argv[], int ret)
{                   // For loop that stops when indexing is equal to the
                    // number of arguments.
    for(int idx = 1; idx != argc; ++idx) 
                    // Use stoi to convert strings to int, in order to
                    // sum them up in ret. 
        ret += std::stoi(argv[idx]);

    return ret;
}
