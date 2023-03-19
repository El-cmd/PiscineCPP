#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{}

void PhoneBook::Header()
{
	std::cout << "\033[01;34m _____________________________________________________________\n\033[00m";
	std::cout << "\033[01;34m7     77  7  77     77     77     77  _  77     77     77  7  7\n\033[00m";
	std::cout << "\033[01;34m|  -  ||  !  ||  7  ||  _  ||  ___!|   __||  7  ||  7  ||   __!\n\033[00m";
	std::cout << "\033[01;34m|  ___!|     ||  |  ||  7  ||  __|_|  _  ||  |  ||  |  ||     |\n\033[00m";
	std::cout << "\033[00;34m|  7   |  7  ||  !  ||  |  ||     7|  7  ||  !  ||  !  ||  7  |\n\033[00m";
	std::cout << "\033[00;34m!__!   !__!__!!_____!!__!__!!_____!!_____!!_____!!_____!!__!__\n\033[00m";
}

void    PhoneBook::add(int x)
{
    m_contact[x].newContact(x + 1);
}

void    PhoneBook::search()
{
    int x = 0;
    int nb;
    std::string prompt;
    std::cout << " -------------------------------------------" << std::endl;
    std::cout << "|  INDEX   |FIRSTNAME | LASTNAME | NICKNAME |" << std::endl;
    std::cout << " -------------------------------------------" << std::endl;
    while (1)
    {
        if (x >= 8)
            break ;
        m_contact[x].printindex();
        m_contact[x].printFname();
        m_contact[x].printLname();
        m_contact[x].printnick();
        x++;
    }
    std::cout << std::endl;
    std::cout << ">>> ";
    std::getline(std::cin, prompt);
    nb = atoi(prompt.c_str());
    while (nb < 1 || nb > 8 || m_contact[nb - 1].printOrNot() == 0)
    {
        if (nb == 0)
            return ;
        std::cout << "\033[00;31mError: Its not a contact's index; Please enter a valid number: (0 for return);\n\033[00m" << std::endl;
        std::cout << ">>> ";
        std::getline(std::cin, prompt);
        nb = atoi(prompt.c_str());
    }
    m_contact[nb - 1].printContact();
}