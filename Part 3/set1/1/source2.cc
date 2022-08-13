#include <iostream>
#include "pointerunion.h"                   // Header with pointer union

template <typename Type>                    // Only declare template
Type justReturn(Type const &nr);             // instead of an include

void fun()
{
  PointerUnion ptrUnion = { justReturn };   // Init 

  // Print adress of function pointer
  std::cout << "Adress of template pointer: " << ptrUnion.vp << '\n';
}