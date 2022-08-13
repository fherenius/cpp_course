#include <iostream>
#include <ostream>
#include <ios>

int main(int argc, char **argv)
{
  std::ostream out(std::cout.rdbuf());
  
  out.setstate(std::ios::failbit);
  
  for (size_t idx = 0, it_nr = std::stoull(argv[1]); idx != it_nr; ++idx)
  {
    if(out.good())
      out << "Nr. of command line arguments: " << argc << '\n';

    //out << "Nr. of command line arguments: " << argc << '\n';
  }
}
