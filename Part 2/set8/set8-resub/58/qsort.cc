//JB: ?
#include "main.ih"

// Quicksort using iterators
void quicksort(vector<int>::iterator begin, vector<int>::iterator end)
{
    // If it's less than 2 elements long, it's already sorted
    if (end - begin < 2)
        return;

    // Partition the vector 
    auto rhsBegin = partition(begin + 1, end, bind2nd(less<int>(), *begin));
    auto lhsEnd = rhsBegin - 1;

    swap(*begin, *lhsEnd);

    // Send both partitioned vectors to separate threads that
    // recursively call quicksort to sort the rest of the vector
    future<void> lhs = async(quicksort, begin, lhsEnd);
    future<void> rhs = async(quicksort, rhsBegin, end);

    lhs.wait(); // Wait for futures to be available
    rhs.wait(); // before continuing

    //JB: According to CppReference, the destructor of a future *may* delay
    //JB: until the future has been made ready. In that case, you only start
    //JB: printing when the array is indeed sorted. Is there a way to make more
    //JB: sure that it is?
    //FPJ: Added the appropriate wait members
}
