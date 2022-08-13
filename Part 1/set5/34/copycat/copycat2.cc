#include "copycat.ih"

CopyCat::CopyCat(char **data)
:
    d_size(nElements(data)),              // count array elems and set
    d_data(ntbsCopy(data, d_size))        // deep copy of array
{ 
}
