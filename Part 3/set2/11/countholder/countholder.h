#ifndef __COUNTERHOLDER_H__
#define __COUNTERHOLDER_H__

#include <cstddef>

class Countholder
{
    static size_t s_count;
    static size_t s_actual;

  public:
    Countholder();
    ~Countholder();
    size_t &count() const;  // count.f
    size_t &actual() const; // actual.f
};

inline Countholder::Countholder()
{
  ++s_count; // Increment count and actual
  ++s_actual;
}

inline Countholder::~Countholder()
{
  --s_actual; // Only decrement current existing objects
}

#endif // __COUNTERHOLDER_H__