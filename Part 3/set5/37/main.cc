template <typename Type> // Concept to check that add/subtract
concept Add =            // Operators are available
  requires (Type lhs, Type rhs)
  {
    lhs + rhs;
    lhs - rhs;
  };

template <typename Type> // Concept to check multiple/division operators
concept Mul =            // are available
  requires (Type lhs, Type rhs)
  {
    lhs * rhs;
    lhs / rhs;
  };

template <typename Type> // Concept for either Add, Mul or Both
concept AddMul =
  Add<Type> || Mul<Type>; // Use logical OR operator to allow either or both to
                          // be valid

template <typename Type>  // Concept for exclusively Add or Mul
concept AddOrMul =        
  Add<Type> != Mul<Type>; // Use != to basically use an XOR