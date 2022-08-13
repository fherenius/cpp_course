#include <iostream>

#include "counter/counter.h"

int main()
{
  Counter<int> int1 { 32 };
  Counter<int> int2;

  Counter<double> dbl1;
  Counter<double> dbl2 { 32.4 };

  std::cout << "Int objects constructed: " << int1.count() << '\n'
            << "Int objects available: " << int2.actual() << '\n'
            << "Double objects constructed: " << dbl1.count() << '\n'
            << "Double objects available: " << dbl2.actual() << '\n';

  // Now destruct some objects
  dbl1.~Counter();
  int2.~Counter();

  std::cout << "Int objects available after destruction: " << int1.actual()
            << '\n'
            << "Double objects available after destrc: " << dbl2.actual()
            << '\n';
}