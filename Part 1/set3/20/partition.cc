#include "quicksort.ih"

size_t partition(string *strings, size_t left, size_t right)
{
    size_t pivot = left;

    while (left < right)
    {
                                    // left element is greater than pivot 
        if (tolower(strings[left]).compare(tolower(strings[pivot])) > 0)
        {
            --right;                // decrement right
                                    // move left element to rightmost position
            swap(strings[left], strings[right]);
        }                           
        else                        // left element is smaller or equal to pivot
        {
                                    // swap left and pivot
            swap(strings[left], strings[pivot]);
            pivot = left;           // assign left new pivot
            ++left;                 // increment left
        }
    }
    return pivot;    
}