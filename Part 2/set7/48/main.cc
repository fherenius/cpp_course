#include "main.ih"



int main(int argc, char **argv)
{
  // Starting time
  auto const start = std::chrono::system_clock::now();
  auto const startTime = std::chrono::system_clock::to_time_t(start);

  size_t const nrPrimes = std::atoi(argv[1]); // number of primes to find

  auto primes = calcPrimes(nrPrimes);
  printPrimes(primes);

  // End of calculations
  auto const end = std::chrono::system_clock::now();
  auto const endTime = std::chrono::system_clock::to_time_t(end);
  std::chrono::duration<double> timeSpend = end-start; 

  // Print output info:
  std::cout << std::setw(20) << std::left << "Starting time: " 
            << std::put_time(std::localtime(&startTime), "%F %T") << '\n'
            << std::setw(20) << std::left << "Ending time: " 
            << std::put_time(std::localtime(&endTime), "%F %T") << '\n'        << "Computation of " << nrPrimes << " took " << timeSpend.count()
            << " seconds" << '\n';
}