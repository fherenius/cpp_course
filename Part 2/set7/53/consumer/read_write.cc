#include "consumer.ih"

void Consumer::read_write()
{
  if (!d_storage.empty()) // Only grab a line if storage not empty
  {                       // This implements polling
    std::string strOut = d_storage.dequeue(); // Get front line
    d_out << strOut.c_str() << '\n';        // Write to output stream
    ++d_size;                               // Increment size member
  }
}