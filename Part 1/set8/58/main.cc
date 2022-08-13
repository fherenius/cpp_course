#include "numbers/numbers.h"
#include <iostream>

int main()
{
    Numbers numbers1(2, 4);

    Numbers numbers2(numbers1);

    Numbers numbers3;
    numbers3 = numbers2;

    numbers3.write(std::cout);
}