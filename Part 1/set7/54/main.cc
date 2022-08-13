#include "Lock/Lock.h" // lock header
#include <iostream> // cout
#include <string>
#include <fstream> // fstream

int main(int argc, char **argv)
{
  std::string pathString = argv[1]; // Get path passed as argument
  char *pathChar = argv[1];
  Lock lockFile{ pathString }; // Create lock object

                                    // Open output stream and seek end of stream
                                    // to append
  std::ofstream out(pathChar, std::ios_base::out | std::ios_base::app); 

  std::string line; // Line to append to stream
  std::cout << "? "; // Prompt for input
  std::getline(std::cin, line); // Store cin into line

  out << line << '\n';
}
