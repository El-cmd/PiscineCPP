#include "Serializer.hpp"

int main(void)
{
	Data test;

	test.a = 42;
	
	std::cout << "Before conversion of : " << test.a << " into uintptr" << std::endl;

	uintptr_t i = Serializer::serialize(&test);
	Data *new_test;
	new_test = Serializer::deserialize(i);
    std::cout << std::endl;

	std::cout << "After conversion of : " << test.a << " into uintptr" << std::endl;
	return 0;
}