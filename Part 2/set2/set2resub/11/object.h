#include <iostream>
#include <string>

class Object {
    
    std::string d_name;

    public:
        Object(std::string const &name);            // constructor
        

        Object(Object const &other);           // copy constructor
        

        void throwException();                // exception throwing function
        

        void rethrow();                       // rethrow the catched exception
        

        std::string name();
};

inline Object::Object(std::string const &name)             // constructor
:
    d_name(name)
{
    std::cout << "Constructing Object " << d_name << '\n';
}

inline Object::Object(Object const &other)    // copy constructor
:
    d_name(other.d_name + " copy")
{
    std::cout << "Copy constructor for " << d_name << '\n';
}

inline void Object::throwException()          // exception throwing function
{
    throw Object("localObject");;
}

inline void Object::rethrow()                // rethrow the catched exception
{
    throw;
}

inline std::string Object::name()
{
    return d_name;
}