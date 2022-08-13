#include <iostream>
#include "pointerunion.h" // Header with pointerunion
#include "justreturn.h"   // Header with template 

void fun()
{
  PointerUnion ptrUnion = { justReturn };  // Init 

  // Print adress of function pointer
  std::cout << "Adress of template pointer: " << ptrUnion.vp << '\n';
}
