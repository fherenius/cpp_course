#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <cstddef>
#include <iostream>
#include <iterator>

template <typename Class, typename BaseIterator, typename Type> class Iterator
{
    BaseIterator d_current; // Holds current
                            // iterator

  public:
    // Declare iterator tags, in line with new method:
    using iterator_category = std::random_access_iterator_tag;
    using value_type        = Type;
    using difference_type   = std::ptrdiff_t;
    using pointer           = value_type *;
    using reference         = value_type &;

    Iterator(BaseIterator const &current); // copy constructor

    Type     &operator*();                             // dereferenceop.f
    Iterator &operator++();                            // incrementop.f
    Iterator &operator--();                            // decrementop.f
    int       operator-(Iterator const &rhs) const;    // minusop.f
    Iterator  operator+(int step) const;               // plusstepop.f
    Iterator  operator-(int step) const;               // minusstepop.f
    Type     *operator->();                            // pointyop.f
    bool      operator<(Iterator const &rhs) const;    // smallerop.f
    bool      operator==(Iterator const &other) const; // equalop.f
    bool      operator!=(Iterator const &other) const; // inequalop.f
};

#include "copyconstructor.f"
#include "decrementop.f"
#include "dereferenceop.f"
#include "equalop.f"
#include "incrementop.f"
#include "inequalop.f"
#include "minusop.f"
#include "minusstepop.f"
#include "plusstepop.f"
#include "pointyop.f"
#include "smallerop.f"

#endif // __ITERATOR_H__