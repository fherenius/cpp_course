//JB: 1

#ifndef INCLUDED_CHARS_H
#define INCLUDED_CHARS_H

#include <tuple>
#include <ostream>
#include <string>

    // General template, used when charList is empty
template<char ...charList>
struct Chars
{};

    // Recursive template specialization, unpacks one character from list
template <char first, char ...charList>
struct Chars<first, charList...>
{};

    // Base case specialization, unpacks the last character
template <char first>
struct Chars<first>
{};


    // Prints the first character of the template parameter list as it
    // unpacks it.
template <char first, char ...charList>
std::ostream &operator<<
(
    std::ostream &out,
    Chars<first, charList...> const &chars
)
{
    out << first;
    return out << Chars<charList...>();
}

    // Prins the last character in the char list as it is unpacked
template <char first>
std::ostream &operator<<(std::ostream &out, Chars<first> const &chars)
{
    return out << first;
}

    // Only used on empty char list, prints nothing
template <char ...charList>
std::ostream &operator<<(std::ostream &out, Chars<charList...> const &chars)
{
    return out;
}

#endif

