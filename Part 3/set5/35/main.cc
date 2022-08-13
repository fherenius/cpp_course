#include <concepts>

template <typename Type>
concept Dereferenceable  =
  requires (Type const &tp)
  {
    *tp; 
  };

template <Dereferenceable Type>
auto add(Type &lhs, Type &rhs) -> Type
{
  return lhs + rhs;
};

template <Dereferenceable Type>
class Add
{
  Type d_data;
};

int main()
{
  int a = 3;
  int b = 5;
  int c = add(a,b);

  Add<int> sampleClass;
  return 0;
}