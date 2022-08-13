#include "Strings/strings.h"
#include <iostream>

int main(int argc, char **argv)
{
  Strings str(argc, argv);
  std::cout << "Str: " << str.at(1) << '\n';
}
