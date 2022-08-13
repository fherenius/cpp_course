#include "main.ih"


bool prime(std::vector<size_t> &primes, size_t next)
{
  bool isPrime = true;            // bool to track if next is prime

                                  // iterate over vector
  for(auto it = primes.begin(); it != primes.end(); ++it)
  {
    if (!(next % *it))  // if next is divisible by prime, its not a prime
    {
      isPrime = false;  // not a prime
      break;            // dont have to check against more numbers
    }
  }

  return isPrime;
}