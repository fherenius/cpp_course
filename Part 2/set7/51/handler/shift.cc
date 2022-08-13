#include "handler.ih"

void Handler::shift(std::ostream &out, std::string const &text)
{
    out << text << '\n';        // output original string

    std::string rotated = text;
    for (size_t idx = 1; idx < rotated.length(); ++idx)
    {
                                // Rotate string
        std::rotate(rotated.begin(), rotated.begin() + 1, rotated.end()); 
        out << rotated << '\n'; // Output rotated string 
    }

}