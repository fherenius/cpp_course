#include "main.ih"

void read_write(Storage &storage, std::ofstream &out)
{
  if (!storage.empty()) // Only grab a line if storage not empty
  {                     // This implements polling
    std::string strOut = storage.dequeue(); // Get front line
    out << strOut.c_str() << '\n';          // Write to output stream
  }
}