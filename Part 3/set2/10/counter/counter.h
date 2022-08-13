#ifndef __UNIQUE_H__
#define __UNIQUE_H__

#include <memory>

template <typename Type>
class Counter
{
  std::unique_ptr<Type> d_data;
  static size_t s_count;
  static size_t s_actual;

  public:
    Counter();                           // default constructor
    Counter(Type data);                  // counter.f
    Counter(Type *data);                 // counterptr.f
    Counter(Counter<Type> const &other);  // Copy constructor
    Counter(Counter<Type> &&tmp);         // Move constructor
    ~Counter();                           // destructor

    Counter<Type> &operator=(Counter<Type> const &other); // copyassignment.f
    Counter<Type> &operator=(Counter<Type> &&tmp);        // moveassignment.f

    Type &get();        // get1.f
    Type &get() const;  // get2.f
    size_t &count() const;  // count.f
    size_t &actual() const; // actual.f
};

template <typename Type>
size_t Counter<Type>::s_count = 0;

template <typename Type>
size_t Counter<Type>::s_actual = 0;

#include "counter.f"
#include "counterptr.f"
#include "copyconstr.f"
#include "moveconstr.f"
#include "copyassignment.f"
#include "moveassignment.f"
#include "get1.f"
#include "get2.f"
#include "count.f"
#include "actual.f"

template <typename Type>
inline Counter<Type>::~Counter()
{
  --s_actual; // Decrement available objects
}

template <typename Type>
inline Counter<Type>::Counter() // Default constructor incrementing counters
{
  ++s_actual;
  ++s_count;
}

#endif // __UNIQUE_H__