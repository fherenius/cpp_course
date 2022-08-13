#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <memory>
#include <string>
#include <vector>

class Strings
{
    std::vector<std::shared_ptr<std::string>> d_str;

    public:
        Strings() = default;
        Strings(int argc, char **argv);    // 2.cc
        explicit Strings(char *environLike[]);       // 3.cc

        size_t size() const;
        size_t capacity() const;
        void reserve(size_t request);
        void resize(size_t count);

        std::string const &at(size_t idx) const;
        std::string &at(size_t idx);

        std::string &operator[](size_t idx);
        std::string const &operator[](size_t idx) const;
        Strings &operator+=(std::string const &rhs);
};

inline size_t Strings::size() const
{
    return d_str.size();
}

inline size_t Strings::capacity() const
{
  return d_str.capacity();
}

inline void Strings::reserve(size_t request)
{
  d_str.reserve(request);
}

inline std::string const &Strings::at(size_t idx) const
{
  return *d_str.at(idx);
}

inline std::string &Strings::at(size_t idx)
{
  return *d_str.at(idx);
}

inline std::string &Strings::operator[](size_t idx)
{
  return *d_str[idx].get();
}

inline Strings &Strings::operator+=(std::string const &rhs)
{
  d_str.emplace_back(std::make_shared<std::string>(rhs));
  return *this;
}

inline void Strings::resize(size_t count)
{
  d_str.resize(count);
}

inline std::string const &Strings::operator[](size_t idx) const
{
  return *d_str[idx];
}



#endif

