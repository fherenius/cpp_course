#include "data.ih"

void Data::swapWordDoubleArray(Data &other)
{
	double (*tmp)[10] = other.u_double;

	new (&other.u_word) string{ std::move(u_word) };
	u_word.~string();

	u_double = tmp;
}
