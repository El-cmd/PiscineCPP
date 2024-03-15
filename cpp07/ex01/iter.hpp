#ifndef ITER_HPP
	#define ITER_HPP

#include <string>
#include <iostream>

template <typename T> void iter(T *string, size_t length, void (*ptrfunct)(T &))
{
	for (size_t i = 0; i < length; i++) ptrfunct( string[i] );
}


template <typename T> void print(T &a)
{
	std::cout << a << std::endl;
}


#endif