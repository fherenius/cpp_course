#include "main.ih"

void lexInput(Scanner &scanner, std::vector<std::string> &container)
{
  while (scanner.lex())
    container.push_back(scanner.matched());
}