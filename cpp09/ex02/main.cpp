#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac >= 2)
		{
			std::string arg;
			int i = 1;
			while (av[i])
			{
				arg = arg + av[i];
				arg = arg + " ";
				i++;
			}
			PmergeMe Tri(arg);
			Tri.Run();
		}
		else
			throw std::invalid_argument("The PmergeMe program needs more than one argument");
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << ROUGE << "Error: " << e.what() << REINIT << std::endl;
	}
}