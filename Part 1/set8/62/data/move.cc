#include "data.ih"

void Data::move(Data &&tmp, Type current, Type next)
{
	swap(tmp, current, next);
}
