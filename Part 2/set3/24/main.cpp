#include <iostream>
#include <string>
#include <iterator>

std::string *factory(std::string const &str, size_t count)
{
  static std::string s_str = str;       // Declare as static variable
                                        // so that it can be accessed in Strings

  struct Strings: public std::string {  // Local struct that inherits
      Strings()                         // Default constructor with no args
      :
        std::string(s_str)              // Construct string with s_str
        {}
  };

  return new Strings[count];            // Init count Strings containing str
}

int main()
{
  std::string *sp = factory("Test", 5);

                                         // Copy each string into std::cout
  std::copy(sp, sp + 5, std::ostream_iterator<std::string>{
    std::cout, "\n"});
}
