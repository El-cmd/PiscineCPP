#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		(void)av;
		if (ac == 2)
		{
			
		}
		else
			throw std::invalid_argument("The RPN needs 2 arguments");
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << ROUGE << "Error: " << e.what() << REINIT << std::endl;
	}
}