#include "main.ih"
                                        // Recursive fun to sort an array of
                                        // strings
void quicksort(std::string stringArr[], size_t left, size_t right)
{
  if (left < right)                     // Put limit in recursion
  {
                                        // Partition array
    size_t pivot = partition(stringArr, left, right);

                                        // Recurse with partitioned arrays
    quicksort(stringArr, pivot + 1, right);
    quicksort(stringArr, left, pivot);
  }
}
