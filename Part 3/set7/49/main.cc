#include "main.ih"

int main(int argc, char *argv[])
{
  Scanner                  scanner;   // Initialise scanner
  std::vector<std::string> container; // Init vector

  if (argc == 1)
    lexInput(scanner, container); // Parse file
  else
  {
    ++argv; // skip program name
    --argc; // remove 1 from argc

    for (int idx = 0; idx != argc; ++idx) // Loop over possible files
    {
      scanner.switchIstream(argv[idx]); // Switch stream to next file
      lexInput(scanner, container);     // Parse file
    }
  }

  std::sort(container.begin(), container.end()); // Sort vector

  std::cout << "Sorted words: " << '\n';

  for (auto const &str : container) // Print sorted vector
    std::cout << str << '\n';
}