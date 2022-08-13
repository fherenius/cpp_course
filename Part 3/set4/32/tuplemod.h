#ifndef INCLUDED_TUPLEMOD_H
#define INCLUDED_TUPLEMOD_H

#include "extendtuple.hi"

template <typename Tuple>
class TupleMod
{

    Tuple const &d_tuple;       // the available tuple

  public:
    TupleMod(Tuple const &tuple);

    template <typename ...AddParams>    // returns new tuple to which
    auto add(AddParams &&...addParams) const; // AddParams were added

};

template <typename Tuple>
TupleMod<Tuple>::TupleMod(Tuple const &tuple)
:
    d_tuple(tuple)
{}


template <typename Tuple>
template <typename ...AddParams>    // returns new tuple to which
auto TupleMod<Tuple>::add(AddParams &&...addParams) const // AddParams were added
{
    enum { size = std::tuple_size<Tuple>::value };
    return
        ExtendTuple<Tuple, Nr<size>, AddParams...>::
        extend(d_tuple, std::forward<AddParams>(addParams)...);
}

#include "unpackadd.hi"

template <typename ...Lhs, typename ...Rhs>
auto operator+(std::tuple<Lhs...> const &lhs,
               std::tuple<Rhs...> const &rhs)
{

    using LhTuple = std::tuple<Lhs...>;                 // Get the types
    using RhTuple = std::tuple<Rhs...>;

    enum { size = std::tuple_size< RhTuple >::value };  // Get size of rhtuple     

    return                                              // Add together through
                                                        // TupleMod and Unpack
        UnpackAdd<TupleMod<LhTuple>, RhTuple, Nr<size>>::
        unpackAdd(TupleMod<LhTuple>{ lhs }, rhs);
}


#endif

