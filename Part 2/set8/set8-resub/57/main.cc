//JB: 0
#include <iostream>
#include <numeric>
#include <iterator>
#include <future>

using namespace std;

enum
{ 
    LHSROWS = 4,
    COLS = 5,
    RHSROWS = 6
};

// FPJ: Compared to last version, this now takes pointers
//      to the start and end of the relevant arrays.
//      No more global data
double innerProduct(double &lhsBegin, double &lhsEnd, double &rhsTbegin)
{
    return inner_product(lhsBegin, lhsEnd, rhsTbegin, 0);
}

int main()
{
    // left matrix to mulitply
    double const lhs[LHSROWS][COLS] = {{1, 2, 3, 4, 5}, 
                        {2, 1, 5, 4, 3}, 
                        {5, 4, 3, 2, 1}, 
                        {4, 3, 2, 1, 5}};
    //JB: What? Global data! And not even const. Why?
    //FPJ: Changed to local + enum names, and made const 

    // right matrix to mulitply
    double const rhsT[RHSROWS][COLS] = {{1, 2, 3, 4, 5}, 
                        {2, 1, 5, 4, 3}, 
                        {5, 4, 3, 2, 1}, 
                        {4, 3, 2, 1, 5},
                        {2, 1, 5, 4, 3}, 
                        {5, 4, 3, 2, 1}};
    //JB: Even though the dimensions are clearly fixed, I'd still give them enum
    //JB: names. That way, you still have to change the initializations of
    //JB: course, but after that, you don't need to separate the 4s and 6s that
    //JB: mean vector lengths from 4s and 6s that mean something completely
    //JB: different.
    //FPJ: Changed to enum names. That is a bit nicer :) 

    size_t const lhsRows = LHSROWS;      // amount of rows on lhs
    size_t const rhsCols = RHSROWS;      // amount of rows on rhs
    //JB: modifiable? Not even const, let alone enums?
    //FPJ: Made const
    
    future<double> fut[4][6];               // holds result of multiplicaiton
    for (size_t row = 0; row != lhsRows; ++row)
    {
        for (size_t col = 0; col != rhsCols; ++col)
        {                                   // create task for every index
            //JB: Lazy auto.
            //FPJ: Removed lazy auto
            packaged_task innerProductTask = packaged_task<double(size_t,
                                                size_t)> (innerProduct);
                                            // get future from task
            fut[row][col] = innerProductTask.get_future();        
            thread(                         // execute task in separate thread
                move(innerProductTask), 
                begin(lhs[row]),
                end(lhs[row]),
                begin(rhsT[col])).detach();  
        }
    }

    for (size_t row = 0; row != lhsRows; ++row)
    {                                       // output result
        for (size_t col = 0; col != rhsCols; ++col)
            cout << fut[row][col].get() << ' ';
        cout << '\n';
    }
}
