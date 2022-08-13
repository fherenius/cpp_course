#include <iostream>
#include <utility>

template<typename Functor, typename ...Params>
void forwarder(Functor functor, Params &&...params) // Use "&&..." to accept
{                                                   // multiple args
  functor(std::forward<Params>(params)...); // std::forward ensures params are
}                                           // forwarded to function call

class Demo {};

void fun(int first, int second) 
{
  std::cout << "fun(" << first << ", "
            << second << ")\n";
}
void fun(Demo &&dem1, Demo &&dem2) {}

int main()
{
  // Specifically tell the compiler the type of 
  // function pointer it should be expecting.
  forwarder<void (*)(int, int)>(fun, 1, 3);
  forwarder<void (*)(Demo &&, Demo &&)>(fun, Demo{}, Demo{});
}
        