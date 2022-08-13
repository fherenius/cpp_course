#include <iostream>

using namespace std;

class MaxFour
{
    
    public:
        static size_t s_nMaxFour;       // keep track of number of objects
        
        MaxFour();          
        ~MaxFour();
};

inline MaxFour::MaxFour()
{

    if (s_nMaxFour >= 4)
        throw string("max. number of objects reached");
    
    ++s_nMaxFour;                       // increment number of maxfour objects

    cout << s_nMaxFour << " MaxFour objects created\n";
}

inline MaxFour::~MaxFour()
{
    cout << "Destructor called\n";
}

inline size_t MaxFour::s_nMaxFour;

int main(int argc, char const *argv[])
{
    MaxFour *mf = nullptr;

    try
    {
        mf = new MaxFour[10];  // construct 10 objects
    }
    catch(string &e)
    {
        cerr << e << '\n';
    }
    
    delete[] mf;
}
