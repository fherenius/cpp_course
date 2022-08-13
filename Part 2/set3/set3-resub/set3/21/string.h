#ifndef INCLUDED_STRINGS_H_
#define INCLUDED_STRINGS_H_

#include <string>

class String: public std::string
{
    // friend functions
    friend bool operator==(String const &lhs, String const &rhs);   // equals 
    friend bool operator!=(String const &lhs, String const &rhs);   // neq 
    friend bool operator>(String const &lhs, String const &rhs);    // greater 
    friend bool operator>=(String const &lhs, String const &rhs);   // geq
    friend bool operator<(String const &lhs, String const &rhs);    // less
    friend bool operator<=(String const &lhs, String const &rhs);   // leq

    public:
        String(size_t count, std::string const &str);

        String &insert(std::string const &text);        // insert at beginning
        using std::string::string;       
};

inline bool operator==(String const &lhs, String const &rhs)
{
    return lhs.compare(rhs) == 0;
}

inline bool operator!=(String const &lhs, String const &rhs)
{
    return !(lhs == rhs);
}

inline bool operator<=(String const &lhs, String const &rhs)
{
    return lhs.compare(rhs) <= 0;
}

inline bool operator<(String const &lhs, String const &rhs)
{
    return lhs.compare(rhs) < 0;
}

inline bool operator>(String const &lhs, String const &rhs)
{
    return !(lhs <= rhs);           // > is negation of <= 
}

inline bool operator>=(String const &lhs, String const &rhs)
{
    return !(lhs < rhs);            // >= is negation of <
}

#endif