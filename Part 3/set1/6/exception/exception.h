#ifndef INCLUDED_EXCEPTION_
#define INCLUDED_EXCEPTION_

#include <string>
#include <sstream>
#include <exception>

class Exception: public std::exception
{
    template <typename Type>             // Declare template as friend function
    friend Exception &&operator<<(Exception &&in, Type const &input);

    std::string d_what;

    public:
        Exception() = default;
        char const *what() const noexcept(true) override;   
};
        
template <typename Type>                 // Definition of friendly template
Exception &&operator<<(Exception &&in, Type const &input)
{
    std::ostringstream oss;
    oss << input;            // Use sstream to insert any type
    in.d_what += oss.str();  // Add input to exception string
    return std::move(in);    // Move string
};

#endif




