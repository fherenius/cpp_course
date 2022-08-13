#include "consumer.ih"

Consumer::Consumer(Storage &storage, std::string filename)
:
  d_storage(storage),
  d_out(filename)
{}