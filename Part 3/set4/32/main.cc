#include <iostream>
#include "tuplemod.h"


using namespace std;


int main()
{
    tuple<double, double> t1{ 1.0, 12.5 };

    TupleMod< tuple<double, double> > tmod(t1);
    
    auto t2 = t1 + t1;
    cout << tuple_size< decltype(t2) >::value << '\n';  // shows 4
    
    auto t3 = tmod.add(12.0);
    cout << tuple_size< decltype(t3) >::value << '\n';  // shows 3
}
