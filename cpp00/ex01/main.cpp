#include "includes/PhoneBook.hpp"

int main(void)
{
	PhoneBook Repertoire;
	std::string input;
	int x = 0;

	Repertoire.Header();
	while (42)
	{
		std::cout << std::endl;
		std::cout << ">>> \e[92;5;118mADD (Ajoute un contact)\e[0m | >>> \e[93;5;226mSEARCH (Affiche et recherche les contacts)\e[0m | >>> \033[00;31mEXIT (Quitte le menu)\033[00m" << std::endl;
		std::cout << std::endl;
		std::cout << ">>> ";
		if (!(std::getline(std::cin, input)))
            break ;
		std::cout << std::endl;
		if (input == "ADD")
		{
			Repertoire.add(x);
			x++;
			if (x == 8)
				x = 0;
		}
		else if (input == "SEARCH")
			Repertoire.search();
		else if (input == "EXIT")
			return 0;
		else
			std::cout << "\033[00;31mError: >>> Its not a command valid of this application.\n\033[00m" << std::endl; 
	}
	return 0;
}