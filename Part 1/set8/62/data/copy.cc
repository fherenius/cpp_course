#include "data.ih"

void Data::copy(Data const &other, Type current, Type next)
{
	Data tmp{ other, next };
	swap(tmp, current, next);
	tmp.destroy(current);
}
