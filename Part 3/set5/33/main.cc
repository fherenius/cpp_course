#include <iostream>

// Define concept
template <typename Type>
concept BasicMath = 
  requires (Type lh, Type rh)
  {
    lh + rh; // Require + operator
    lh - rh; // Require - operator
    lh * rh; // Require * operator
    lh / rh; // Require / operator
    -lh;     // Require unary minus for both lhs/rhs
    -rh;     // Require unary minus
  };

template <BasicMath Lhs, BasicMath Rhs> // Add function requiring BasicMath concept
Lhs add(Lhs lhs, Rhs rhs)
{
  return lhs + rhs;
};

int main()
{
  int a = 3;
  int b = 5;

  // Test add function
  std::cout << add(a, b) << '\n';
            << add(a, std::string("Ola.")) << '\n'; 

  // using string returns conflicting types of parameter
  // shows that most operators are not defined for the std::string type
}