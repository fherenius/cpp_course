#include "scanner/Scanner.h"
#include <iostream>

int main()
{
  Scanner scanner; // Init scanner

  scanner.lex(); // Lex input

  std::cout << '\n' // Empty line for clarity
            << "Amount of single chars: " << scanner.chars() << '\n'
            << "Amount of identifiers: " << scanner.idents() << '\n'
            << "Amount of integral nrs: " << scanner.ints() << '\n'
            << "Amount of real nrs: " << scanner.reals() << '\n';
}