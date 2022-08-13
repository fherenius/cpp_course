#include "main.ih"

                    // Function to sum doubles.
double sum(int argc, char *argv[], double ret)
{
    for (int idx = 1; idx != argc; ++idx) 
                    // Use stod to convert strings to doubles, in order
                    // to sum them up in ret.
        ret += std::stod(argv[idx]);

    return ret;
}
