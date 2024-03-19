#include "Span.hpp"


int main(void)
{
	Span test(12);
	test.addNumber(12);
	test.addNumber(0);
	test.addNumber(54);
	test.addNumber(542);
	test.addNumber(78);
	test.addNumber(57);
	std::cout << test.longestSpan() << std::endl;
	std::cout << test;
	return 0;
}