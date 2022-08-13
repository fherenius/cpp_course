#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;

    while (true)
    {
        try
        {
            cout << "please enter a number: ";
            getline(cin, line);
            if (line == "q")
            {
                cout << "leaving...\n";
                return 0;
            }
            cout << stod(line) << '\n';
        }
        catch (invalid_argument const &e)
        {
            cerr << "\'" << line << "' is not a number\n";
        }
    }

}