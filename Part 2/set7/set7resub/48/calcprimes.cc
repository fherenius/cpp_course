#include "main.ih"

std::vector<size_t> calcPrimes(size_t const nrPrimes)
{
  auto dotsObj = NewlineOnExit{std::jthread(dots)};
  auto primes = sieve(nrPrimes);
  
  dotsObj.stop();

  return primes;
}