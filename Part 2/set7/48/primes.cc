#include "main.ih"

std::vector<size_t> sieve(size_t const amount)
{ 
  std::vector<size_t> primes{2}; // Initialise with first prime
  size_t next(3);                // Start at 3

  while (primes.size() < amount) // Go until amount of primes is reachead
  {
    bool isPrime = prime(primes, next); // See if 'next' is a prime

    if (isPrime)
      primes.push_back(next);     // append to vector if it is a prime 
    
    ++next;                       // next prime to check
  }

  return primes;
}

bool prime(std::vector<size_t> &primes, size_t &next)
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