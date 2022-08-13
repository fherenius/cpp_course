#include <iostream>
#include <future>
#include <iomanip>

// Fill lhs and rhs matrixes with arbitrary values
double lhs[4][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, 
                    {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};
double rhsT[6][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10},
                     {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20},
                     {21, 22, 23, 24, 25}, {26, 27, 28, 29, 30}};

double innerProduct(size_t rowLhs, size_t rowRhs)
{
  size_t rowSize = 5; // Length of the row vector
  double sum = 0;     // Init sum to 0

  // Sum all elements individually
  for (size_t idx = 0; idx != rowSize; ++idx)
    sum += lhs[rowLhs][idx] * rhsT[rowRhs][idx];

  return sum; // Return, to be retrieved by future
}

int main()
{
  std::future<double> fut[4][6]; // Initialise future
  size_t lhsRows = 4; // Amount of rows for lhs
  size_t rhsRows = 6; // Amount of rows for rhs

  // Loop over lhs rows
  for (size_t lhsRow = 0; lhsRow != lhsRows; ++lhsRow)
  {
    // For every lhs row, get the inner product of each rhsRow (since rhs is
    // transposed)
    for (size_t rhsRow = 0; rhsRow != rhsRows; ++rhsRow)
    {
      // Define the packaged task
      std::packaged_task<double (size_t row, size_t col)> task(innerProduct);

      // Assign future value
      fut[lhsRow][rhsRow] = task.get_future(); 

      // Run task in detached thread
      std::thread( std::move(task), lhsRow, rhsRow ).detach(); 
    }
  }

  // For all lhs/rhs rows, print value in result matrix
  for (size_t lhsRow = 0; lhsRow != lhsRows; ++lhsRow)
  {
    for (size_t rhsRow = 0; rhsRow != rhsRows; ++rhsRow)
      std::cout << std::setw(5) << fut[lhsRow][rhsRow].get();

    std::cout << '\n'; // Newline between rows
  }
}