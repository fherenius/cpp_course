#ifndef INCLUDED_PARSER_
#define INCLUDED_PARSER_

#include "parser.ih"

class Parser
{
    Line d_line;
    bool d_integral;
    enum Return
    {
        NO_NUMBER,
        NUMBER,
        EOLN
    };

    public:
        Parser();

        bool reset();                   // fills d_line with next input line
        Return number(double *dest);    // returns value in next substring
        bool isIntegral() const;
        string next();

    private:
        Return convert(double *dest, std::string const &str);
        bool pureDouble(double *dest, std::string const &str);
};
        
#endif
