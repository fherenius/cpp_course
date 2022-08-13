#include "main.ih"

ReturnValues combine(int argc, char **argv) 
{
    bool ok = argc > 1 && stoi(argv[1]) <= argc;    // check if args are valid
    size_t nr = ok ? stoul(argv[1]) : 0;            // get requested arg nr
    string value = ok ? argv[nr - 1] : "";          // extract value of arg
    return ReturnValues{ok, nr, value};             
}