#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	try
	{
		if (ac == 2)
		{
			BitcoinConverter test("input.csv");
		}
		else
			throw std::invalid_argument("Need 1 arg : -> bsd");
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}