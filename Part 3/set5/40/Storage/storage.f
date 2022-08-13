#include "storage.h"

template <typename Data>
inline Storage<Data>::iterator::iterator(
    std::vector<Data *>::iterator const &current) :
    d_current(current)
{
}

template <typename Data>
inline Storage<Data>::iterator::iterator()
:
  d_current()
{}

template <typename Data> inline void Storage<Data>::push_back(Data *data)
{
  d_storage.push_back(data);
}

template <typename Data> inline Storage<Data>::iterator Storage<Data>::begin()
{
  return d_storage.begin();
}

template <typename Data> inline Storage<Data>::iterator Storage<Data>::end()
{
  return d_storage.end();
}

/*
template <typename Data>
inline Storage<Data>::reverse_iterator Storage<Data>::rbegin()
{
  return d_storage.rbegin();
}

template <typename Data>
inline Storage<Data>::reverse_iterator Storage<Data>::rend()
{
  return d_storage.rend();
}
*/

template <typename Data>
inline Storage<Data>::iterator &Storage<Data>::iterator::operator++()
{
  ++d_current;
  return *this;
}

template <typename Data>
inline Storage<Data>::iterator Storage<Data>::iterator::operator++(int)
{
  return iterator(d_current++);
}

template <typename Data>
inline Storage<Data>::iterator &Storage<Data>::iterator::operator--()
{
  --d_current;
  return *this;
}

template <typename Data>
inline Storage<Data>::iterator Storage<Data>::iterator::operator--(int)
{
  return iterator(d_current--);
}


template <typename Data> inline Data &Storage<Data>::iterator::operator*()
{
  return *d_current;
}

template <typename Data> inline Data *Storage<Data>::iterator::operator->()
{
  return &**d_current;
}

template <typename Data>
inline Storage<Data>::iterator &Storage<Data>::iterator::operator+=(int step)
{
  d_current += step;
  return *this;
}

template <typename Data>
inline Storage<Data>::iterator &Storage<Data>::iterator::operator-=(int step)
{
  d_current -= step;
  return *this;
}