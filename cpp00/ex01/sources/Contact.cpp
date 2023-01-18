#include "../includes/Contact.hpp"

Contact::Contact()
{}

void Contact::newContact(int x)
{
	m_index = x;
	std::cout << "First Name >>> ";
	std::getline(std::cin, m_fName);
	while (m_fName.empty())
	{
		std::cout << "\033[00;31mNo empty line please.\033[00m" << std::endl;
		std::cout << ">>> ";
		std::getline(std::cin, m_fName);
	}
	std::cout << "Last Name >>> ";
	std::getline(std::cin, m_lName);
	while (m_lName.empty())
	{
		std::cout << "\033[00;31mNo empty line please.\033[00m" << std::endl;
		std::cout << ">>> ";
		std::getline(std::cin, m_lName);
	}
	std::cout << "Nickname >>> ";
	std::getline(std::cin, m_nickname);
	while (m_nickname.empty())
	{
		std::cout << "\033[00;31mNo empty line please.\033[00m" << std::endl;
		std::cout << ">>> ";
		std::getline(std::cin, m_nickname);
	}
	std::cout << "Phone number >>> ";
	std::getline(std::cin, m_pNumber);
	while (m_pNumber.empty())
	{
		std::cout << "\033[00;31mNo empty line please.\033[00m" << std::endl;
		std::cout << ">>> ";
		std::getline(std::cin, m_pNumber);
	}
	std::cout << "Secret >>> ";
	std::getline(std::cin, m_secret);
	while (m_secret.empty())
	{
		std::cout << "\033[00;31mNo empty line please.\033[00m" << std::endl;
		std::cout << ">>> ";
		std::getline(std::cin, m_secret);
	}
	std::cout << std::endl;
}

int	Contact::printOrNot()
{
	if (m_fName.length() < 1)
		return 0;
	return 1;
}

void Contact::printindex()
{
	std::cout << "|";
	std::cout << std::right << std::setw(10) << m_index;
	std::cout << "|";
}

void Contact::printFname()
{
	if (m_fName.length() > 10)
		std::cout << std::right << std::setw(9) << m_fName.substr(0, 9) << ".|";
	else
		std::cout << std::right << std::setw(10) << m_fName << "|";
}

void Contact::printLname()
{
	if (m_lName.length() > 10)
		std::cout << std::right << std::setw(9) << m_lName.substr(0, 9) << ".|";
	else
		std::cout << std::right << std::setw(10) << m_lName << "|";
}

void Contact::printnick()
{
	if (m_nickname.length() > 10)
		std::cout << std::right << std::setw(9) << m_nickname.substr(0, 9) << ".|";
	else
		std::cout << std::right << std::setw(10) << m_nickname << "|";
	std::cout << std::endl << " -------------------------------------------" << std::endl;
}

void Contact::printContact()
{
	std::cout << "First Name >>> ";
	std::cout << m_fName << std::endl;
	std::cout << "Last Name >>> ";
	std::cout << m_lName << std::endl;
	std::cout << "Nickname >>> ";
	std::cout << m_nickname << std::endl;
	std::cout << "Phone number >>> ";
	std::cout << m_pNumber << std::endl;
	std::cout << "Secret >>> ";
	std::cout << m_secret << std::endl;
	std::cout << std::endl;	
}