//JB: 0
#ifndef INCLUDED_BIN_H
#define INCLUDED_BIN_H

#include <bitset>
#include <cmath>

template <size_t DecNr>
struct Bin
{   
        // Create the bitset with needed size to get the full value
    using Bits = std::bitset<static_cast<size_t>(log(DecNr)) + 2>;

        // Compute the bitset (it has a constexpr constructor)
    static constexpr Bits const value = Bits{ DecNr };
};

#endif

/* JB:
   This may or may not work. But it delegates all work to std::bitset and log.
   There's no recursion between templates of your own writing. As such, it's not
   a Template MetaProgram, and not good preparation for e.g. traits classes.

   Please roll your own, for practice.
 */
