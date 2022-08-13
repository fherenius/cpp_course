#ifndef INCLUDED_OPERATORPLUSEXPR_H
#define INCLUDED_OPERATORPLUSEXPR_H

#include "addition.h"

template <typename LHT, typename RHT,
          template <typename, typename> typename Operator>
class Expr;     // "Forward" declaration


    // To make sure we can use the Expr class we create our own version of
    // std::plus. A policy class that is a functor which returns the addition
template <typename LHS, typename RHS>
auto operator+(LHS const &lhs, RHS const &rhs)
{
    return Expr<LHS, RHS, Addition> { lhs, rhs };
}


#endif

