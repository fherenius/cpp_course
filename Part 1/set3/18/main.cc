#include "main.ih"

int main(int argc, char **argv)
{
    if (!structCall(argc, argv))
        return 0;                       // if invalid args stop program
    boundCall(argc, argv);
    
}
