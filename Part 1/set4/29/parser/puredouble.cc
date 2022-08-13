#include "parser.ih"

bool Parser::pureDouble(double *dest, std::string const &str)
{
    size_t substrSize;
    *dest = stod(str, &substrSize);
    if (substrSize == str.size())           // succesful conversion  
    {                       
        d_integral = str.find_first_of("Ee.") == string::npos; 
        return true;
    }       
    return false;
}
