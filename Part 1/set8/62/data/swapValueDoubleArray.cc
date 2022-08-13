#include "data.ih"

void Data::swapValueDoubleArray(Data &other)
{
	size_t value = u_value;
	u_double = other.u_double;
	other.u_value = value;
}
