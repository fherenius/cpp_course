#ifndef __UNIQUE_H__
#define __UNIQUE_H__

#include "../countholder/countholder.h"

#include <memory>

template <typename Type> class Counter : public Countholder
{
    std::unique_ptr<Type> d_data;

  public:
    Counter() = default;                 // default constructor
    Counter(Type data);                  // counter.f
    Counter(Type *data);                 // counterptr.f
    Counter(Counter<Type> const &other); // Copy constructor
    Counter(Counter<Type> &&tmp);        // Move constructor

    Counter<Type> &operator=(Counter<Type> const &other); // copyassignment.f
    Counter<Type> &operator=(Counter<Type> &&tmp);        // moveassignment.f

    Type          &get();          // get1.f
    Type          &get() const;    // get2.f
};

#include "copyassignment.f"
#include "copyconstr.f"
#include "counter.f"
#include "counterptr.f"
#include "get1.f"
#include "get2.f"
#include "moveassignment.f"
#include "moveconstr.f"

#endif // __UNIQUE_H__