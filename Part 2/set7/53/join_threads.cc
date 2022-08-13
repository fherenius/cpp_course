#include "main.ih"

void joinThreads(std::vector<std::thread> &threadVec)
{
  for (auto it = threadVec.begin(); it != threadVec.end(); ++it)
    it->join();
}