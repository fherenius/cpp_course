#include "Workforce/workforce.h"

#include <string>

int main()
{
  Workforce WorkForce;                       // Create workforce
  WorkForce.run("test.txt", "test_out.txt"); // Start execution and 
                                             // pass input/output files
}