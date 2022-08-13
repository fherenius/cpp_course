#ifndef __STORAGE_H__
#define __STORAGE_H__

#include "../Iterator/iterator.h"

#include <iterator>
#include <vector>

template <typename Data> class Storage
{
    std::vector<Data *> d_storage; // Holds data

  public:
    void  push(Data *data); // Member to push data
    Data &at(size_t idx);   // Member to access data
    typedef Iterator<Storage, typename std::vector<Data *>::iterator, Data>
        iterator; // Typedef for iterator (uses iterator class)
    typedef std::reverse_iterator<iterator>
                     reverse_iterator; // typedef for reverse iterator
    iterator         begin();  // Begin iterator
    iterator         end();    // End iterator
    reverse_iterator rbegin(); // Begin reverse iterator (so end())
    reverse_iterator rend();   // End reverse iterator (so begin())
};

template <typename Data> inline void Storage<Data>::push(Data *data)
{
  d_storage.push_back(data);
}

template <typename Data> inline Data &Storage<Data>::at(size_t idx)
{
  return *d_storage.at(idx);
}

template <typename Data> inline Storage<Data>::iterator Storage<Data>::begin()
{
  return iterator(d_storage.begin());
}

template <typename Data> inline Storage<Data>::iterator Storage<Data>::end()
{
  return iterator(d_storage.end());
}

template <typename Data>
inline Storage<Data>::reverse_iterator Storage<Data>::rbegin()
{
  return reverse_iterator(end());
}

template <typename Data>
inline Storage<Data>::reverse_iterator Storage<Data>::rend()
{
  return reverse_iterator(begin());
}
#endif // __STORAGE_H__