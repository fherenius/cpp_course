#include "scanner/Scanner.h"
#include <iostream>

int main()
{
  Scanner scanner; // Init scanner

  while (int token = scanner.lex()) // Lex input
  {
    std::string const &text = scanner.matched(); // Store matched text

    switch (token)
    {
      case Scanner::CHAR:
        std::cout << int(text.c_str()[0]) << ": " << text.c_str() << '\n';
        break;
      case Scanner::IDENTIFIER:
        std::cout << "identifier: " << text.c_str() << '\n';
        break;
      case Scanner::INT:
        std::cout << "integral number: " << text.c_str() << '\n';
        break;
      case Scanner::REAL:
        std::cout << "real number: " << text.c_str() << '\n';
        break;
      case Scanner::OPERATOR:
        std::cout << "operator: " << text.c_str() << '\n';
        break;
      case Scanner::STRING:
        std::cout << "string: " << text.c_str() << '\n';
        break;
      default: break;
    }
  }
}