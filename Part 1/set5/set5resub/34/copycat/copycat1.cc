#include "copycat.ih"

CopyCat::CopyCat(int argc, char const * const *argv)
:
  d_size(argc),                         // initialise to array length
  d_data(ntbsCopy(argv, d_size))        // deep copy of argv
{}
