#include <iostream>
#include <cctype>

int main(int ac, char **av)
{	
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int j = 1;  av[j]; j++)
			for (int i = 0;  av[j][i]; i++)
				std::cout << (char)std::toupper(av[j][i]);
		std::cout << std::endl;
	}
    return (0);
}