#include "combis.ih"

// generate combinations of req elements for nTotal objects
void combisForSize(size_t idx, size_t req, bool bits[])
{
    if (!req){               // combination is complete
        print(bits);
        return;
    }
                                // loop over leftover bits         
    for (size_t i = idx; i < nTotal; ++i)
    {
        bits[i] = 1;            // put bit i in combination
                                // recurse for leftover bits
        combisForSize(i + 1, req - 1, bits);
        bits[i] = 0;            // remove bit i from combination
    }
}