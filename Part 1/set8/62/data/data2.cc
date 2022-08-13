#include "data.ih"

Data::Data(std::string const &word)
{
	new (&u_word) string{ word };
}
