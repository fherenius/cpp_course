#include "main.ih"

// Fill consumer vector with objects
void fillObjectVector(std::vector<Consumer> &vec, Storage &store,
                      int amount, char **filenames)
{
  for (int idx = 0; idx != amount; ++idx)
    vec.push_back( Consumer(store, std::string(filenames[idx])) );
}