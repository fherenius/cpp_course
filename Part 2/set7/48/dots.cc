#include "main.ih"

void dots(std::stop_token stop)
{
  while (not stop.stop_requested())
  {
    std::cerr << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
