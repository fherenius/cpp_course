#ifndef INCLUDED_NOENTRY_
#define INCLUDED_NOENTRY_

#include <string>


class NoEntry
{
    friend class PrivilegedOne;

    std::string d_name;
    size_t d_area = 0;
    size_t d_date = 0;

    public:
        std::string const &name() const;
        size_t area() const;
        size_t date() const;

    private:
        NoEntry(NoEntry const &other) = default;
        NoEntry() = default;
        NoEntry(std::string const &name, size_t area, size_t date);
};

inline NoEntry::NoEntry(std::string const &name, size_t area, size_t date)
:
    d_name(name),
    d_area(area),
    d_date(date)
{}

inline size_t NoEntry::area() const
{
    return d_area;
}

inline size_t NoEntry::date() const
{
    return d_date;
}

inline std::string const &NoEntry::name() const
{
    return d_name;
}

#endif