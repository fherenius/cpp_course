#include "person.ih"

void Person::insert(ostream &out) const
{
    out << name() << '\n' << address() << '\n' 
        << phone() << '\n' << mass() << '\n';
}