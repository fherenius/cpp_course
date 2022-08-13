//JB: ?
#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H

#include <vector>
#include <string>
#include <sstream>
#include "typer.h"

class Data
{
    std::vector<std::string> d_data;

  public:
    template <typename TypeT>
    Typer<TypeT>::return_type get(size_t idx) const;

    void push_back(std::string const &str);
};

void Data::push_back(std::string const &str)
{
    d_data.push_back(str);
}

template <typename TypeT>
Typer<TypeT>::return_type Data::get(size_t idx) const
{
    if constexpr (TypeT ret; Typer<TypeT>::convert)     // Convert if needed
    {                                                   // i.e. for basic types
        std::stringstream store { d_data[idx] };        // sstream can do it
        store >> ret;                                   // for us to correct
        return ret;                                     // types
    }
    else
        return d_data[idx];
}


#endif

/* JB:
   This works, but it requires something as big and unwieldy as a stringstream,
   and it doesn't require much metaprogramming.
   Please try and use stod, stoi and the like, and metaprogram to get the right
   function to bear on the string, i.e. to distinguish between string, floating
   point, and integer types.
 */
