//JB: 1
#ifndef INCLUDED_ADDITION_H
#define INCLUDED_ADDITION_H


template <typename LHT, typename RHT>
struct Addition
{
    auto operator ()(LHT const &lhs, RHT const &rhs);
};

    // Test to see how to use the defines
    // although this might not be the most useful case ;-)
#define tHDR_ template <typename LHT, typename RHT>
#define ADD_ Addition<LHT, RHT> 

    // Definition of the function operator of addition
    // like std::plus in the end
tHDR_ auto ADD_::operator ()(LHT const &lhs, RHT const &rhs)
{
    return lhs + rhs;
}


#undef ADD_
#undef tHDR_

#endif

