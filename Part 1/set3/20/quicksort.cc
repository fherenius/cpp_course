#include "quicksort.ih"

void quicksort(string *strings, size_t left, size_t right)
{
    
    if (left >= right)
        return;

    size_t p = partition(strings, left, right);

    quicksort(strings, left, p);
    quicksort(strings, p + 1, right);
}