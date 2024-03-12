#include "Serializer.hpp"

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *a;
	a = reinterpret_cast<Data*> (raw);
	return (a);
}


uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t a;
	a = reinterpret_cast<uintptr_t>(ptr);
	return a;
}