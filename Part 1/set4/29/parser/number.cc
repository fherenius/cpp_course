#include "parser.ih"

Parser::Return Parser::number(double *dest)
{
    string str = d_line.next();
    if (str.empty())
        return Return::EOLN;
    return convert(dest, str);
}
