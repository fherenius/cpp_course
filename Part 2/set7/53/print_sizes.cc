#include "main.ih"

void printSizes(std::vector<Consumer> &consumerVec)
{
  for (size_t idx = 0; idx != consumerVec.size(); ++idx)
    std::cout << "Lines processed by consumer " << idx << " is: "
              << consumerVec.at(idx).size() << '\n';
}