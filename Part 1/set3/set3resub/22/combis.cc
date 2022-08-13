#include "combis.ih"

void combis(size_t idx, bool bits[])
{                                   // generate combinations for at least
                                    // req elements
    for (size_t req = nTotal; req > nRequired; --req)
        combisForSize(idx, req, bits);    
}