#include <chrono>
#include <iostream>
#include <iomanip>
#include "inputtotime.cc"

using namespace std::chrono;

int main(int argc, char **argv)
{
  auto const timenow = system_clock::now();  // Current time 
  auto const nowtimet = system_clock::to_time_t(timenow); // to time_t

  auto inputTime = inputToTime(argv[1]);

  auto const nowMinusInput = system_clock::to_time_t(timenow - inputTime);

  // Current time input to string for a clean output :)
  std::ostringstream out;
  out << "Current time - " << argv[1] << " in localtime: "; 

  std::cout << std::setw(35) << std::left << "Current time in localtime: "
            << std::put_time(std::localtime(&nowtimet), "%F %T") << '\n'
            << std::setw(35) << std::left << "Current time in UTC: "
            << std::put_time(std::gmtime(&nowtimet), "%F %T") << '\n'
            << std::setw(35) << std::left << out.str()
            << std::put_time(std::localtime(&nowMinusInput), "%F %T") << '\n';
}