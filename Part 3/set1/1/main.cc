#include <iostream>
#include "justreturn.h"
#include "pointerunion.h"

void fun(); // Forward declare function to be linked later

int main()
{
  PointerUnion ptrUnion = { justReturn }; // Create union with pointers

  // Print location in memory of function
  std::cout << "Location of function in main: " << ptrUnion.vp << '\n';

  fun(); // Call fun, show that the location is the same.
}