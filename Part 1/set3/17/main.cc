#include "sum.ih"

int main(int argc, char **argv)
{
    cout << (containsDouble(argc, argv) // sum as doubles if contains a dot
        ? sum(argc, argv, 0.0)          // otherwise sum as integers
        : sum(argc, argv, 0))  << "\n";
}