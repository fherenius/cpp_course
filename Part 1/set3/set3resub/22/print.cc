#include "combis.ih"

void print (bool const bits[])
{
    for (size_t idx = 0; idx < nTotal; ++idx)
    {
        if (bits[idx])              // output number if bit is set
            cout << idx << " "; 
    }
    cout << "\n";
}