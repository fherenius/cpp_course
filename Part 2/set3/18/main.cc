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
}

class Derived : public Base
{
  public:
    Derived() {};
    Derived(Derived const &other) {};
    Derived(Derived &&tmp) {};
};

int main()
{
  Derived derive;
  Derived deriveTwo(derive);
  Derived deriveThree( std::move(derive) );
}
