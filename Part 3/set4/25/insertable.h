//JB: 1
#ifndef INCLUDED_INSERTABLE_H
#define INCLUDED_INSERTABLE_H

#include <ostream>
//JB: If you use 'class' here instead of 'typename', perhaps you intend this to
//JB: compile for older versions of C++ too. In that csae, it makes sense to use
//JB: '<typename...>' for the template template parameter, as on older versions,
//JB: the number of parameters the TTP takes must match.
template <template <typename> class Container, typename Data>
struct Insertable : public Container<Data>
{
        // As we provide a new constructor the other constructors have to be
        // specified as well as the container's constructor will not be
        // automatically used anymore
    Insertable() = default;
    Insertable(Data const &val);
    Insertable(Data &&val);

    // JB: There's a simpler way to get these. (One line.)
    Insertable(Container<Data> const &other);
    Insertable(Container<Data> &&other);

};


template <template <typename> class Container, typename Data>
std::ostream &operator<<
    (
        std::ostream &out, 
        Insertable<Container, Data> const &insertable
    );

#endif

