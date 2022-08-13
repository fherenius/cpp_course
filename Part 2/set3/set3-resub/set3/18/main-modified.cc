#include <iostream>

class Base
{
  public:
    Base();
    Base(Base const &other);
    Base(Base &&tmp);
};

inline Base::Base()
{
  std::cout << "Base constructor." << '\n';
}

inline Base::Base(Base const &other) 
{
 std::cout << "Base copy." << '\n';
}

inline Base::Base(Base &&tmp) 
{ 
  std::cout << "Base move." << '\n'; 
};

class Derived : public Base
{
  public:
    Derived();
    Derived(Derived const &other);
    Derived(Derived &&tmp);
};

inline Derived::Derived() 
{};

inline Derived::Derived(Derived const &other) 
{
  // Base(other)            // Call copy constructor
  // Base(std::move(other)) // Call move constructor
};

inline Derived::Derived(Derived &&tmp) 
{};



class Derived : public Base
{
  public:
    using Base::Base;
};

int main()
{
  Derived derive;
  Derived deriveTwo(derive);
  Derived deriveThree( std::move(derive) );
}
