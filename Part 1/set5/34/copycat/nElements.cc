#include "copycat.ih"

size_t CopyCat::nElements(char const* const* input)
{
    size_t inputSize = 0;                 // Init var holding size

    while (input[inputSize] != 0)         // Count until ntb found
        ++inputSize;

    return inputSize;                    // Return count
}
