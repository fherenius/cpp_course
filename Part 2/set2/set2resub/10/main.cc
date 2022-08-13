#include <iostream>

using namespace std;

class Arg
{
    public:
        static Arg const &instance(unsigned argc, char **argv, 
                                    char const *arguments);
};

class Process
{
    public:
        Process(Arg const &arg);
        void run();
};

void processArgs(int argc, char **argv, char const *arguments)
{
    Arg const &arg = Arg::instance(argc, argv, arguments);      // 1

    Process process{ arg };                                     // 2

    process.run();                                              // 3
}

int main(int argc, char **argv)
try
{
    processArgs(argc, argv, "ace:fg:h");
}
catch (int value)                           // catch integer
{
    if (value)
        return 1;
    
    return 0;
}
catch (string &message)                     // catch string
{
    cerr << message;
    return 1;
}
catch (exception &exc)                      // catch exception
{
    cerr << exc.what();
    return 1;
}