#include "maxFour.ih"

MaxFour::MaxFour()
{

    if (s_nMaxFour >= 4)
        throw string("max. number of objects reached");
    
    ++s_nMaxFour;                       // increment number of maxfour objects

    cout << s_nMaxFour << " MaxFour objects created\n";
}