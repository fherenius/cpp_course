#ifndef __STORAGE_H__
#define __STORAGE_H__

#include <algorithm>
#include <compare>
#include <iostream>
#include <iterator>
#include <vector>

template <typename Data> class Storage
{
    std::vector<Data *> d_storage; // store the pointers to the data
                                   // cleanup allocated memory:
                                   // DIY.
  public:
    class iterator;
    //using reverse_iterator = std::reverse_iterator<iterator>;
    void             push_back(Data *data);
    iterator         begin();
    iterator         end();
    //reverse_iterator rbegin();
    //reverse_iterator rend();
};

template <typename Data> struct Storage<Data>::iterator
{
    friend auto operator<=><>(iterator const &lhs, iterator const &rhs);
    friend bool operator==<>(iterator const &lhs, iterator const &rhs);

    friend int  operator-<>(iterator const &lhs, iterator const &rhs);

    friend auto operator+<>(iterator const &lhs, int step);
    friend auto operator-<>(iterator const &lhs, int step);

    using iterator_category = std::random_access_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = Data;
    using pointer           = value_type const *;
    using reference         = value_type const &;

  private:
    std::vector<Data *>::iterator d_current;

  public:
    iterator();
    // sort(rbegin, rend) needs the constructor
    // hence public.
    iterator(std::vector<Data *>::iterator const &current);

    iterator   &operator--();
    iterator    operator--(int);
    iterator   &operator++();
    iterator    operator++(int);

    iterator   &operator+=(int step); // increment over `n' steps
    iterator   &operator-=(int step); // decrement over `n' steps

    Data       &operator*();
    Data       *operator->(); // access the fields of the
                              // struct an iterator points
                              // to. E.g., it->length()
};

#include "operators.f"
#include "storage.f"
#endif // __STORAGE_H__