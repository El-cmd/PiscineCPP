#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	(void)av;
	try
	{
		if (ac == 2)
		{
		
		}
		else
			throw std::invalid_argument("The PmergeMe program needs one argument");
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << ROUGE << "Error: " << e.what() << REINIT << std::endl;
	}
}