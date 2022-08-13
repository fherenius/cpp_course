#include "newlineonexit.ih"

NewlineOnExit::~NewlineOnExit()
{
  if (d_thread.joinable())
  {
    d_thread.join();    // Join thread
    std::cout << '\n';  // Print a newline
  }
}