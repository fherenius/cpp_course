#include "data.ih"

void Data::swapDoubleArrayDoubleArray(Data &other)
{
	double (*tmp)[10] = other.u_double;
	other.u_double = u_double;
	u_double = tmp;
}
