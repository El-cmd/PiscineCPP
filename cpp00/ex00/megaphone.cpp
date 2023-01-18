#include <iostream>

char	ft_toupper(char c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

int main(int ac, char **av)
{	
	int i = 0;
	int j = -1;
	if (ac > 1)
	{
		while (av[++i])
		{
			while (av[i][++j])
			{
				std::cout << ft_toupper(av[i][j]);
			}
			j = -1;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}