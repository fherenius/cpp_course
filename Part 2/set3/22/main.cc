#include <iostream>

using namespace std;

class Base
{
    public:
        void hello();

};

inline void Base::hello()
{
    cout << "Hello from Base\n";
}

class Derived : public Base
{
    public:
        void hello();
};

inline void Derived::hello()
{
    cout << "Hello from Derived\n";
}

void caller(Base &obj)
{
    Derived *der = static_cast<Derived *>(&obj);  // convert to derived pointer
    der->hello();
}

int main(int argc, const char **argv)
{
    Derived der;

    caller(der);
}