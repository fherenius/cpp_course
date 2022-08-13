//string
#include <concepts>
#include <string>

template <typename Data>
struct String
{
    struct iterator
    {
        using value_type        = Data;

        std::string::iterator d_iter;

            // Note the <>: operator== is a function template
            // specialization as 'iterator' is a class template
        friend bool operator==<>(iterator const &lhs, iterator const &rhs);
    };
    iterator begin()
    {
        return iterator{};
    }
};
//=

// The following concept checks that Type is Storage<Data>::iterator, pretty
// much like a function template with parameter Storage<Data>::iterator would
// do. We can't do the latter, but concept-defined types can be used. The
// concept also makes is superfluous to define specific types in the nested
// class which are used to select the matching free operator. The
// concept-based approach cannot accidentally be broken by the user defining
// identical specific types as the concepts approach simply uses the
// templates' types themselves.

//concept
template<typename Type>
concept StringIterator =
    std::same_as<Type,
                 typename String<typename Type::value_type>::iterator>;
//=

//operator
inline bool operator==(StringIterator auto const &lhs,
                       StringIterator auto const &rhs)
{
    return lhs.d_iter == rhs.d_iter;
}
//=

// template <StringIterator Param>
// inline bool operator==(Param const &lhs,
//                        Param const &rhs)
// {
//     return lhs.d_iter == rhs.d_iter;
// }

int main()
{
    String<int> str;
    return str.begin() == str.begin();
}
