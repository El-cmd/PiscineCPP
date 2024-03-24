#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void)av;
	try
	{
		if (ac == 2)
		{
			
		}
		else
			throw std::invalid_argument("Need 2 arguments .exe and bsd");
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}