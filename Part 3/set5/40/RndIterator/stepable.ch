#ifndef INCLUDED_STEPABLE_CH
#define INCLUDED_STEPABLE_CH

#include <concepts>

template <typename TypeT>
concept Stepable =
    requires(TypeT &value)
    {
        { value + 0 } -> std::convertible_to<TypeT>;
        { value - 0 } -> std::convertible_to<TypeT>;
    };


#endif
