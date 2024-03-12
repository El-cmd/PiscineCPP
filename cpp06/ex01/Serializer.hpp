#ifndef SERIALIZER_HPP
	#define SERIALIZER_HPP

# include <cstdlib>
# include <stdint.h>
# include <iostream>

typedef struct Data
{
	int a;
} Data;

class Serializer
{
	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif