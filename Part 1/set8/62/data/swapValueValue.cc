#include "data.ih"

void Data::swapValueValue(Data &other)
{
	size_t value = u_value;
	u_value = other.u_value;
	other.u_value = value;
}
