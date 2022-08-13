//JB: 1
#ifndef INCLUDED_INSERTABLE_H
#define INCLUDED_INSERTABLE_H
#define tHDR_ template <template <typename> class Container, \
                        typename Data>
#include <ostream>


tHDR_ struct Insertable : public Container<Data>
{
        // As we provide a new constructor the other constructors have to be
        // specified as well as the container's constructor will not be
        // automatically used anymore
    Insertable() = default;
    Insertable(Data const &val);
    Insertable(Data &&val);
    
    Insertable(Container<Data> const &other);
    Insertable(Container<Data> &&other);

};

tHDR_ Insertable<Container, Data>::
    Insertable(Data const &val)
{
    Container<Data>::push_back(val);            // Specify push_back of
}                                               // the container


tHDR_ Insertable<Container, Data>::
    Insertable(Data &&val)
{
    Container<Data>::push_back(std::move(val)); // Push back the rref
}


tHDR_ Insertable<Container, Data>::
    Insertable(Container<Data> const &other)
:
    Container<Data>{ other }                    // Use copy constructor of the
{}                                              // container

tHDR_ Insertable<Container, Data>::
    Insertable(Container<Data> &&other)
:
    Container<Data>{ std::move(other) }         // Use move constructor of the
{}                                              // container


tHDR_ std::ostream &operator<<
    (
        std::ostream &out, 
        Insertable<Container, Data> const &insertable
    )
{
    for (Data const &first = *insertable.cbegin(); 
         Data const &val : insertable)
    {
        if (val != first)
            out << ", ";
        out << val;
    }
    return out;
}


#undef tHDR_
#endif

