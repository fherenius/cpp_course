#include "main.ih"

void startThreads(std::vector<std::thread> &thrdVec, 
                  std::vector<Consumer> &consumerVec)
{
  for (auto it = consumerVec.begin(); it != consumerVec.end(); ++it)
    thrdVec.push_back( std::thread( &Consumer::consume, std::ref(*it) ) );
}