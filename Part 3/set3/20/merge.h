//JB: 1
#ifndef INCLUDED_MERGE_H
#define INCLUDED_MERGE_H

#include "../19/chars.h"
#include "onechar.h"



    // Generic template, only used to create the specializations
template
<
    typename LhsT,
    typename RhsT
>
struct Merge;


    // Two Chars specialization, the templates are the char packs
    // used to create the Chars objects.

    // Defines CP as being the Chars object created by the combination 
    // of the two char packs
template
<
    char ...Lhs,
    char ...Rhs
>
struct Merge<Chars<Lhs...>, Chars<Rhs...>>
{
    using CP = Chars<Lhs..., Rhs...>;
};


    // Chars and OneChar specialization.
    // Defines CP as being the Chars created by the pack and the single
    // character
template
<
    char ...Lhs,
    char Rhs
>
struct Merge<Chars<Lhs...>, OneChar<Rhs>>
{
    using CP = Chars<Lhs..., Rhs>;
};

#endif

