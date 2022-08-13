#ifndef __TYPEIDX_H__
#define __TYPEIDX_H__

      // Template for when it is empty
#include <type_traits>
template <typename... Haystack> struct TypeIdx
{
    enum
    {
      value = 0, // If an empty Haystack is ever passed
      found = 0  // found should be set to 0.
    };
};

      // Template specialisation that usually gets called
template <typename Needle, typename TopOfStack, typename... Haystack>
struct TypeIdx<Needle, TopOfStack, Haystack...>
{
    enum
    { // Use std::is_same to compare types, continue recursively looking
      // until either the Haystack is empty (not found) or is_same is true
      value = 1 + (std::is_same<Needle, TopOfStack>::value
                       ? 0
                       : TypeIdx<Needle, Haystack...>::value),
      // Same as value, only then keeping track of if a value has been found
      // or not.
      found = std::is_same<Needle, TopOfStack>::value 
                  ? 1
                  : TypeIdx<Needle, Haystack...>::found
    };
};

#endif // __TYPEIDX_H__