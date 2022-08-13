#include "traitcounter.h"

    // When perfect forwarding everything is regarded as a reference
    // To get whether it is a pointer or a reference we need an extra
    // level of depth
template <typename TypeT>
using PerfectType = TraitCounter<typename TraitCounter<TypeT>::type>;

template <typename TypeT>
PerfectType<TypeT>::type * const      // Get the type we need to return
locate(TypeT &&target)                // Using perfect forwarding we can
{                                     // always get the variable location
    enum { val = PerfectType<TypeT>::value };

    if constexpr (val == 2)           // If we got a pointer we return that
        return target;
    else
        return &target;               // Otherwise the address of the target
}
