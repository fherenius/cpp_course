#include <iostream>

int main(int argc, char **argv)
{
                        // Get input from command-line.
    int input = std::stoi(argv[1]);                 

    for (size_t mul = 1; mul <= 10; mul++){
                        // Print multiplications of input.
        std::cout << mul << " * " << input << " = " << mul * input << "\n";
    }
}