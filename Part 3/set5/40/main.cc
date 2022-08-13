#include <string>
#include <algorithm>
#include <iostream>
#include "Storage/storage.h"

int main(int argc, char **argv)
{
  Storage<std::string> storage;

  while (*argv)
    storage.push_back(new std::string{ *argv++ });

  std::cout << ( storage.begin() - storage.end() ) << '\n';
  /*std::cout << ( storage.begin() < storage.end() ) 
            << ( storage.begin() > storage.end() )
            << ( storage.begin() <= storage.end() )
            << ( storage.begin() >= storage.end() ) << '\n';
  
  */
  //std::sort(storage.begin(), storage.end());
  //std::sort(storage.rbegin(), storage.rend());
}