#include "PmergeMe.hpp"


/* ++++++++++++++++ Coplian Form ++++++++++++++++++++++++*/
PmergeMe::PmergeMe(const std::string &av)
{
	secureAv(av);
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

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/