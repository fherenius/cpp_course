#include "copycat.ih"

char **CopyCat::ntbsCopy(char const* const* input, size_t nElements)
{
    char **output = new char *[nElements];// Allocate memory for string  
    
    for (size_t idx = 0; idx != nElements; ++idx)
        output[idx] = duplicate(output[idx], input[idx]);// Copy string into array

    return(output);
}
