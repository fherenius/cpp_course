#include "Lock/Lock.h"
#include <iostream> // cout
#include <unistd.h> // sleep
#include <string>

int main(int argc, char **argv)
{
  std::string path = argv[1]; // Get path passed as argument

  std::cout << path << '\n';

  Lock lockFile(path);

  while (lockFile.valid() != 0)
  {
    Lock lockFile(path); // try locking again
    sleep(2000);         // wait for two seconds before trying again
  }
  
  std::cout << lockFile.valid() << '\n'; // Was locking succesful?

  std::string lineToAppend;

  std::cout << "? ";
  std::getline(std::cin, lineToAppend);
}
