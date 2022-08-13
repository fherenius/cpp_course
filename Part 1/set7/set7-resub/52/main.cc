// previous rating: JB: ?

#include <chrono>   // chrono::system_clock
#include <ctime>    // localtime
#include <iomanip>  // put_time
#include <iostream> // cout

std::ostream &now(std::ostream &out) // Manipulator to insert cur time
{
  // Original issue with code; too many separate statements that made it quite
  // long

  // Fix: contracted code to fewer lines 

  // Obtain current time
  std::time_t time =
     std::chrono::system_clock::to_time_t( std::chrono::system_clock {}.now() );

  // Set to localtime representation and insert to out
  out << std::put_time(std::localtime(&time), "%c");

  return out;
}

int main()
{
  std::cout << now << '\n';
}
