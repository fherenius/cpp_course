#include "main.ih"

void joinThreads(std::vector<std::thread> &threadVec)
{
  for (auto &it : threadVec)
    it.join();
}