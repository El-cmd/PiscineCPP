#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac == 2)
		{
			RPN Calcule(av[1]);
			Calcule.Run();
		}
		else
			throw std::invalid_argument("The RPN program needs one argument");
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << ROUGE << "Error: " << e.what() << REINIT << std::endl;
	}
}