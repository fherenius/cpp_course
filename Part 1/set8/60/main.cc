#include <iostream>

class Demo
{
  public:
    Demo() // Constructor
    {
      std::cout << "Default constructor used." << '\n';
    }
    ~Demo() // Destructor
    {
      std::cout << "Destructor used." << '\n';
    };

    Demo(Demo const &other) // Copy
    {
      std::cout << "Copy constructor used" << '\n';
    };
    Demo &operator=(Demo const &other) // Copy assign
    {
      std::cout << "Copy assignment used." << '\n';
      return *this;
    };

    Demo(Demo &&tmp) // Move
    {
      std::cout << "Move constructor used." << '\n';
    };
    Demo &operator=(Demo &&tmp) // Move assign
    {
      std::cout << "Move assignment used." << '\n';
      return *this;
    };
};

Demo factory()
{
  return Demo();
};

int main()
{
  Demo one; // Default constructor
  Demo two;

  Demo three(factory()); // Copy elision - normally a move constructor
                         // would be used

  two = one;       // Copy assignment
  two = factory(); // Move assignment
}
