#include <string>

class String: public std::string
{
    public:
        String(size_t count, std::string const &str);

};