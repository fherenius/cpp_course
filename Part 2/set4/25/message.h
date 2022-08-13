#include <iostream>
#include "base.h"

class Message
{
    Base *d_basePtr;
    public:
        Message(Base &base);
        void show(std::ostream &out);
};

inline Message::Message(Base &base)
:
    d_basePtr(&base)
{}

inline void Message::show(std::ostream &out)
{
    d_basePtr->hello(out);
}
