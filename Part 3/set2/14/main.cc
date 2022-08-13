#include "Storage/storage.h"
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
  Storage<std::string> storage;

  std::string astring{ "A string" };
  std::string bstring{ "B string" };

  storage.push(&bstring);
  storage.push(&astring);

  std::cout << "Before sort.\n"
            << "String at pos 0: " << storage.at(0) << '\n'
            << "String at pos 1: " << storage.at(1) << '\n'
            << '\n';

  sort(storage.begin(), storage.end());
  //sort(storage.rbegin(), storage.rend()); Doesn't work!
  
  std::cout << "After sort.\n"
            << "String at pos 0: " << storage.at(0) << '\n'
            << "String at pos 1: " << storage.at(1) << '\n';
}