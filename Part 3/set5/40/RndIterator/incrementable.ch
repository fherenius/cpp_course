#ifndef INCLUDED_INCREMENTABLE_CH
#define INCLUDED_INCREMENTABLE_CH

#include <concepts>

template <typename TypeT>
concept Incrementable =
    requires(TypeT &value)
    {
        { ++value } -> std::convertible_to<TypeT>;
        { value++ } -> std::convertible_to<TypeT>;
    };


#endif