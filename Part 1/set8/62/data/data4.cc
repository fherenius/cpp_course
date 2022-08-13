#include "data.ih"

Data::Data(Data const &other, Type type)
{
	(this->*s_copy[type]) (other);
}
