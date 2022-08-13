#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    string input;
    while (true) 
    {
        cout << "? ";
        if (!getline(cin, input) || input.empty()) // No input --> exit loop.
            break;
                                            // Print reversed from begin to.
        for (auto iterator = input.crbegin(); iterator != input.crend(); ++iterator) 
            cout << *iterator;
        cout << "\n";
    }
}