#ifndef NSTRING_H
#define NSTRING_H

#include <string>

class nString : public std::string
{
  public:
    nString(size_t count, std::string const &str); // Constructor
    using std::string::string;

};

inline nString::nString(size_t count, std::string const &str)
{
  reserve(count * sizeof(str));      // Pre-allocate memory

  for (size_t idx = 0; idx != count; ++idx)  // append str count times
    append(str);
};

#endif //NSTRING_H
