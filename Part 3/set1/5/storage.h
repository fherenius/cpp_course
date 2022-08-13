#ifndef __STORAGE_H__
#define __STORAGE_H__

#include <vector>

class Storage
{
  std::vector<std::size_t> d_data;

  public:
    Storage() = default;
    Storage(std::initializer_list<std::size_t> const &list);

    // In-class template definition
    template <typename Index>
    std::size_t operator[](Index &&idx) const
    {
      // Now construct idx as a size_t
      return d_data[std::size_t(idx)];
    };
    template <typename Index>
    std::size_t &operator[](Index &&idx)
    {
      return d_data[std::size_t(idx)];
    };
};

#endif // __STORAGE_H__