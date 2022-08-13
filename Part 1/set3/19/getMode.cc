#include "main.ih"

Mode getMode(int argc, char **argv)
{
    if (argc < 2)               // not sure 
        return Mode::NONE;

    string arg = argv[1];

    if (arg == "-c")
        return Mode::CHAR_COUNT;

    else if (arg == "-w")
        return Mode::WORD_COUNT;

    else if (arg == "-l") 
        return Mode::LINE_COUNT;
        
    return Mode::NONE;
    
}