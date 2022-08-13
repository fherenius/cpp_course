#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

using namespace std;

vector<int> inputData;

void quicksort(vector<int>::iterator begin, vector<int>::iterator end)
{
    if (end - begin < 2)
        return;

    auto rhsBegin = partition(begin + 1, end, bind2nd(less<int>(), *begin));
    auto lhsEnd = rhsBegin - 1;

    swap(*begin, *lhsEnd);

    future<void> lhs = async(quicksort, begin, lhsEnd);
    future<void> rhs = async(quicksort, rhsBegin, end);
}

int main()
{
    int value;
    while (cin >> value)
        inputData.push_back(value);

    quicksort(inputData.begin(), inputData.end());

    for (auto el: inputData)
        cout << el << ' ';
    cout << '\n';
}
