#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac == 2)
		{
			BitcoinConverter test(av[1]);
			test.Run();
		}
		else
			throw std::invalid_argument("Need 1 arg : => Input");
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << ROUGE << "Error: " << e.what() << REINIT << std::endl;
	}
	return 0;
}