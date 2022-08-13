#include <iostream>
#include "Strings/strings.h"

int main(int argc, char **argv)
{
  Strings strHolder;

  strHolder.resize(1);
  strHolder.reserve(1);
  strHolder.resize(1, argv[2]);
  strHolder += argv[2];

  std::cout << "First entry: " << strHolder.at(1) << '\n';

  Strings strHolder2(argc, argv);
  std::cout << strHolder2.at(1) << '\n'
            << strHolder2[1] << '\n';
}
