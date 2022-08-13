#include "main.ih"

size_t partition(std::string stringArr[], size_t left, size_t right)
{
  size_t pivot = left;                  // Left most element is pivot
  size_t swapLoc = right;               // Location to swap to 

                                        // Reverse loop over the array
  for (size_t idx = (right - 1); idx != left - 1; --idx)
  {
                                        // Compare first characters of array
                                        // objects
    if (tolower(stringArr[pivot][0]) < tolower(stringArr[idx][0]))
    {
      --swapLoc;                        // move swap loc
                                      
                                        // move bigger value to the back of
                                        // the array
      std::swap(stringArr[swapLoc], stringArr[idx]);
    }
  }
                                        // move pivot object to sorted pos.
  std::swap(stringArr[left], stringArr[swapLoc - 1]);
  return (swapLoc - 1);                 // return current pivot location
}
