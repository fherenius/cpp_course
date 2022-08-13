#include <concepts>
#include <iostream>
#include <vector>

// Use template template parameters to be able to specify the template type
// of the used container.
template <template <typename> typename Container, typename Type>
concept HasIndex =
  requires(Container<Type> cont) // Use type as container type
  {
    { cont[0] } -> std::same_as<Type &>; // Check if return type is correct
  };

// Use constrainted templates to check HasIndex for Container<Type>
template <template <typename> typename Container, typename Type>
auto at(Container<Type> container) -> Type requires HasIndex<Container, Type>
{
  return container[1];
} 

int main()
{
  std::vector<int> vec{1, 2};   // Vector to test
  std::cout << at(vec) << '\n'; // Call function, should return 2
  return 0;
}