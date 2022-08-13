#ifndef __UNIQUE_H__
#define __UNIQUE_H__

#include <memory>

template <typename Type>
class Counter
{
  std::unique_ptr<Type> d_data;

  public:
    Counter(Type data);                  // Constructor
    Counter(Type *data);                 // Ptr constructor
    Counter(Counter<Type> const &other);  // Copy constructor
    Counter(Counter<Type> &&tmp);         // Move constructor
    Counter<Type> &operator=(Counter<Type> const &other); // copyassignment.f
    Counter<Type> &operator=(Counter<Type> &&tmp);        // moveassignment.f
    Type &get();        // get1.f
    Type &get() const;  // get2.f
};

#include "copyassignment.f"
#include "moveassignment.f"
#include "get1.f"
#include "get2.f"

template <typename Type>
inline Counter<Type>::Counter(Type data)
:
  d_data(std::make_unique<Type>(data))
{};

template <typename Type>
inline Counter<Type>::Counter(Type *data)
:
  d_data(data)
{};

template <typename Type>
inline Counter<Type>::Counter(Counter<Type> const &other)
:
  d_data(new Type(*other.d_data)) // Deep copy d_data from other 
{};

template <typename Type>
inline Counter<Type>::Counter(Counter<Type> &&tmp)
:
  d_data(std::move(tmp.d_data))
{}


template <typename Type>
class Counter<Type *>
{

};
#endif // __UNIQUE_H__