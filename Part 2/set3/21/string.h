#ifndef INCLUDED_STRINGS_H_
#define INCLUDED_STRINGS_H_

#include <string>

class String: public std::string
{
    public:
        String(size_t count, std::string const &str);

        String &insert(std::string const &text);        // insert at beginning       
};

// free functions
bool operator==(String const &lhs, String const &rhs);   // equals operator
bool operator!=(String const &lhs, String const &rhs);   // neq operator
bool operator>(String const &lhs, String const &rhs);    // greater operator
bool operator>=(String const &lhs, String const &rhs);   // geq operator
bool operator<(String const &lhs, String const &rhs);    // less operator
bool operator<=(String const &lhs, String const &rhs);   // leq operator


inline String &String::insert(std::string const &text)
{
    std::string::insert(0, text);
    return *this;
}

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