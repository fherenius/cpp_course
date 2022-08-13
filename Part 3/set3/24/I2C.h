//JB: 1
#ifndef INCLUDED_I2C_H
#define INCLUDED_I2C_H

    // Generic case of either number or number with characters already created.
    // s_ntbs will point to the static array of its char list specialization
template <size_t number, char ...List>
struct I2C
{
    static constexpr char const *s_ntbs = 
        I2C<number / 10, '0' + (number % 10), List...>::s_ntbs;
};

    // Specialization that creates (and statically holds) the character array
    // formed by the character list. Specialization only called if 0 is reached
    // through a non-zero number.
template <char ...List>
struct I2C<0, List...>
{ 
    static constexpr char const s_ntbs[] = 
        { List..., '\0' };
};

    // Specialization for starting with a zero number
template <>
struct I2C<0>
{
    static constexpr char const s_ntbs[] = 
        { '0', '\0' };
};

#endif

