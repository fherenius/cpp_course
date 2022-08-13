#include "main.ih"

void printPrimes(std::vector<size_t> &primes)
{
  for (auto number : primes)
    std::cout << number << " ";

  std::cout << "\n\n";
}