#ifndef __DECREMENTABLE_H__
#define __DECREMENTABLE_H__

#include <concepts>

template <typename TypeT>
concept Decrementable =
    requires(TypeT &value)
    {
        { --value } -> std::convertible_to<TypeT>;
        { value-- } -> std::convertible_to<TypeT>;
    };
    
#endif // __DECREMENTABLE_H__