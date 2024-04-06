#include "PmergeMe.hpp"


/* ++++++++++++++++ Coplian Form ++++++++++++++++++++++++*/
PmergeMe::PmergeMe(const std::string &av)
{
	initContainers(secureAv(av));
	printBefore(0);
}

PmergeMe::PmergeMe(void)
{}

PmergeMe::~PmergeMe(void)
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/* ++++++++++++++ Gestion erreur + Utils function ++++++++++++++++++++++++ */

std::string PmergeMe::trim(const std::string& str)
{
	size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

std::string PmergeMe::secureAv(const std::string &av)
{
	std::string tmp = trim(av);
	if (tmp.empty())
		throw std::invalid_argument("Argument is empty");
    size_t found = tmp.find_first_not_of("0123456789 ");
    if (found == std::string::npos)
		return tmp;
	else
    	throw std::invalid_argument("Invalid argument: only positive int");
	return tmp;
}

void PmergeMe::printBefore(bool val)
{
	std::cout << "Before: ";
	if (val == 0)
	{
		std::vector<int>::iterator it = this->_vector.begin();
		while (it != this->_vector.end())
		{
			std::cout << *it;
			if (it + 1 != this->_vector.end())
				std::cout << " ";
			it++;
		}
	}
	else
	{
		std::list<int>::iterator it = this->_list.begin();
		while (it != this->_list.end())
		{
			std::cout << *it << " ";
			it++;
		}
	}
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++ Init containers +++++++++++++++++++ */
void PmergeMe::initContainers(std::string tmp)
{
	std::string str;
	char *endptr;
	std::istringstream iss(tmp);
	while (iss >> str)
	{
		if (std::strtol(str.c_str(), &endptr, 10) > INT_MAX || std::strtol(str.c_str(), &endptr, 10) < INT_MIN)
			throw std::overflow_error("No number too big");
		if (*endptr != '\0')
			throw std::overflow_error("Argument converion failed");
		this->_vector.push_back(std::atoi(str.c_str()));
		this->_list.push_back(std::atoi(str.c_str()));
	}
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/