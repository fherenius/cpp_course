#include "data.ih"

void Data::copyWord(Data const &other)
{
	new (&u_word) string{ other.u_word };
}
