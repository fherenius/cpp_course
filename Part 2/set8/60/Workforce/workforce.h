#ifndef WORKFORCECLASS
#define WORKFORCECLASS

#include <iosfwd>

class Workforce
{
  public: 
    Workforce() = default;
    void run(std::string input, std::string output);       // 1
    void run(std::fstream &input, std::fstream &output);   // 2 
};

#endif // !WORKFORCECLASS
