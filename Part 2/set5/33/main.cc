#include <iostream>
#include <set>
#include <iomanip>

int main()
{
  std::multiset<std::string> container;     // Init empty string container
  std::string str;                     // Temp. holds input before insertion

  std::cout << "Enter words: ";        // Prompt user to input

  while (std::cin >> str)              // separate each space separated word
    container.insert(str);             // insert word into container

  std::cout << '\n';                   // Newline after input

  // Hold unique strings in normal set,
  // so that we dont print the same string twice
  std::set<std::string> uniqContainer(container.begin(), container.end());

  std::cout << std::setw(15) << "word"
            << std::setw(15) << "occurences" << '\n';

  for (auto const &idx : uniqContainer)    // Range loop over container
  {
    std::cout << std::setw(15) << idx // Print word
              << std::setw(15) << container.count(idx) << '\n'; // Print freq
  }
}
