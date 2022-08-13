#include <iostream>
#include <set>

int main()
{
  std::set<std::string> container;     // Init empty string container
  std::string str;                     // Temp. holds input before insertion

  std::cout << "Enter words: ";        // Prompt user to input

  while (std::cin >> str)              // separate each space separated word
    container.insert(str);             // insert word into container

  std::cout << '\n';                   // Newline after input

  for (auto const &idx : container)    // Range loop over container
    std::cout << idx << '\n';          // Print each entry to cout
}
