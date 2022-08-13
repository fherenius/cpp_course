#ifndef INCLUDED_TYPER_H
#define INCLUDED_TYPER_H


#include <string>

template <typename TypeT>
struct Typer
{
    using return_type = TypeT;
    enum { convert = 1 }; // JB: Used as bool in data.h. Why not use boolean
                          // JB: values and a bool underlying type?
};

template <>
struct Typer<std::string>                   // Specialization now only works
{                                           // for strings
    using return_type = std::string const &;
    enum { convert = 0 };
};

#endif
