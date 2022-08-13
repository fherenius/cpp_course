#include "main.ih"

using namespace std;


int main(int argc, char *argv[])
{
    size_t idx = 0;
                    // Looping over all command-line chars.
    //JB: There is no newline at the end of the argument list.
    while (*argv[idx] != '\n')
    {
                    // Upon encountering a '.', sum as doubles and end program.
        if (*argv[idx] == '.')
            //JB: FLOW. Action in while-loop suggests it will be run multiple
            //JB: times. But it won't.
        {
            cout << "sum: " << sum(argc, argv, 0.0) << '\n';
            return 0;
        }
        ++idx;
    } //JB: Multiple levels of responsibility.

                    // All command-line args are integers, summing as such.
    cout << "sum: " << sum(argc, argv, 0) << '\n';
}
