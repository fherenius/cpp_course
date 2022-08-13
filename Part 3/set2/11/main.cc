#include "counter/counter.h"

#include <iostream>

int main()
{
  Counter<int>    int1 { 32 };
  Counter<int>    int2;
  Counter<int>    int3 { int1 };

  Counter<double> dbl1;
  Counter<double> dbl2 { 32.4 };

  std::cout << "Objects constructed: " << int1.count() << '\n'
            << "Objects available: " << int2.actual() << '\n';

  // Now destruct some objects
  dbl1.~Counter();
  int2.~Counter();

  std::cout << "Int objects available after destruction: " << int1.actual() 
            << '\n';
}