#include "main.ih"

bool structCall(int argc, char **argv)
{
    ReturnValues retVals = combine(argc, argv);    // get the data from args
    retVals.ok ?                                   // check if vals are valid
        argMsg(retVals.nr, retVals.value) :        // display arg + nr
        usageMsg();                                // display usage info
    return retVals.ok;
}