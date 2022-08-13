#include <chrono>   // chrono::system_clock
#include <ctime>    // localtime
#include <iomanip>  // put_time
#include <iostream> // cout

std::ostream &now(std::ostream &out) // Manipulator to insert cur time
{
  // Get current system_clock time
  std::chrono::time_point curTime = std::chrono::system_clock::now();
  // Convert time_point to time_t type
  std::time_t curTimeT = std::chrono::system_clock::to_time_t(curTime);
  // Convert time_t to tm object
  std::tm currentTime = *std::localtime(&curTimeT);
  // Convert to string, insert to out
  out << std::put_time(&currentTime, "%c");

  return out;
}

int main()
{
  std::cout << now << '\n';
}
