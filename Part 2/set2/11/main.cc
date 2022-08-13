#include <iostream>
#include <string>

using namespace std;

class Object {
    
    string d_name;

    public:
        Object(string name)             // constructor
        :
            d_name(name)
        {
            cout << "Constructing Object " << d_name << '\n';
        }

        Object(Object const &other)    // copy constructor
        :
            d_name(other.d_name + " copy")
        {
            cout << "Copy constructor for " << d_name << '\n';
        }

        void throwException()          // exception throwing function
        {
            Object toThrow("localObject");
            throw toThrow;
        }

        void rethrow()                // rethrow the catched exception
        {
            try
            {
                throwException();
            }
            catch (...)
            {
                throw;
            }

        }

        string name()
        {
            return d_name;
        }
};

int main() try
{
    Object obj("object");
    obj.throwException();
    
    //obj.rethrow();
}
catch(Object obj)
{
    std::cerr << "Exception throws obj: " << obj.name() << '\n';
}
