#include "scanner/Scanner.h"
#include <iostream>

int main(int argc, char *argv[])
{
  Scanner scanner; // Init scanner

  scanner.switchIstream(argv[1]); // Switch input stream only

  scanner.lex(); // Lex input
}