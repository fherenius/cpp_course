#include "data.ih"

void Data::destroyWord()
{
	u_word.~string();
}
