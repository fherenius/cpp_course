#include "main.ih"

int main(int argc, char **argv)
{
    size_t count = 0;
    switch (getMode(argc, argv))
    {
        case Mode::CHAR_COUNT:
            count = countChars();
            break;
        case Mode::WORD_COUNT:
            count = countWords();
            break;
        case Mode::LINE_COUNT:
            count = countLines();
            break;
        case Mode::NONE:
            cout << "mode not available\n";
    }
    cout << count << '\n';
} 
 