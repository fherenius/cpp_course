#include "sum.ih"
                                       // sums arguments as doubles
double sum(int argc, char **argv, double sum)
{
    for (int idx = 1; idx < argc; ++idx)
        sum += stod(argv[idx]);        // convert string to double, add to sum
    return sum;
}
