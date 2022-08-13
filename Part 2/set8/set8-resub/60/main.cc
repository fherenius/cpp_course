#include "Workforce/workforce.h"

#include <string>

int main()
{
  std::string inFile = "main.cc";           // Initialise filenames
  std::string outFile = "out.txt";

  Workforce WorkForce;                       // Create workforce
  WorkForce.run(inFile, outFile);            // Start execution and 
                                             // pass input/output files
}