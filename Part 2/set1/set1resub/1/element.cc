#include "numbers.ih"

int &Numbers::element(size_t idx) const
{
    if (idx < d_size)                       // Check if element exists
        return d_nums[idx];

    std::cout << "Index out of bounds.";
    return d_nums[0];                       // Exit program if index out
                                            // of bounds
}