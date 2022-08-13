#include "main.ih"

void usage(std::string progname)
{
                                // Find last '/'
  if (size_t pos = progname.rfind('/'); pos != std::string::npos)
    progname.erase(0, pos + 1); // Remove chars until '/'

  std::cout << "Usage: " << progname << R"R( [path]

Where:
  path - file to manipulate

The file is either created or opened and a .lck file will be created for lock
administration.

Usage example: ./main example.txt
)R";
}
