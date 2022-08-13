#include "sum.ih"
                                       // sums arguments as integers
int sum(int argc, char **argv, int sum)
{
    for (int idx = 1; idx < argc; ++idx)
        sum += stoi(argv[idx]);        // convert string to int, add to sum
    return sum;
}
