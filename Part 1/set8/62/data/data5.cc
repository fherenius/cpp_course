#include "data.ih"

Data:: Data(Data &&tmp, Type type)
{
	swap(tmp, Type::SIZE_T, type);
}
