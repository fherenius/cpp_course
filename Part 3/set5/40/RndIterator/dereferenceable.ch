#ifndef INCLUDED_DEREFERENCEABLE_CH
#define INCLUDED_DEREFERENCEABLE_CH

#include <concepts>

template <typename TypeT>
concept Dereferenceable =
    requires(TypeT value)
    {
        { *value } -> std::same_as<typename TypeT::value_type &>;
    };

#endif