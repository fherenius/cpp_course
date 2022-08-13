#include "strings.ih"

Strings::Strings(int argc, char *argv[])
:
    d_size(argc),
    d_capacity(argc),
    d_str(rawStrings(argc))
{
    fill(argv);
}
