#include "combis.ih"

int main(int argc, char **argv)
{    
    nTotal = stoul(argv[1]);        // convert combination values from command 
    nRequired = stoul(argv[2]);     // line and store in global values

    bool bits[nTotal];
                                    // initialize bit array
    for (size_t idx = 0; idx < nTotal; ++idx)
        bits[idx] = false;
        
    combis(0, bits);
}