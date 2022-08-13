#include "main.ih"

int main()
{
    // Initialise vector with data
    vector<int> inputData;

    int value;                      // Value to hold input in
    while (cin >> value)
        inputData.push_back(value); // Add value to vector

    // Call quicksort, it splits into threads itself
    quicksort(inputData.begin(), inputData.end());

    // Print output data
    for (auto elem : inputData)
        cout << elem << ' ';
    cout << '\n';
}
