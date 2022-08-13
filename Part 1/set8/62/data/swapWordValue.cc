#include "data.ih"

void Data::swapWordValue(Data &other)
{
	size_t value = other.u_value;

	new (&other.u_word) string{ std::move(u_word) };
	u_word.~string();

	u_value = value;
}
