#include "PmergeMe.hpp"

/* ++++++++++++++++ Coplian Form ++++++++++++++++++++++++*/
PmergeMe::PmergeMe(const std::string &av)
{
	initContainers(secureAv(av));
	secureDouble();
	if (this->_vector.size() < 2)
		throw std::logic_error("PmerMe program needs at least 2 numbers");
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
 /* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
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

void PmergeMe::secureDouble(void)
{
	std::vector<int> tmp = this->_vector;
	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 1; i < tmp.size(); ++i) {
        if (tmp[i - 1] == tmp[i]) {
            throw std::logic_error("No same numbers"); // Doublon trouvé
        }
    }
    return ;
}

int PmergeMe::alreadySorted(void)
{
	int a;
	std::vector<int>::iterator it = this->_vector.begin();
	a = *it;
	it++;
	while (it != this->_vector.end())
	{
		if (a > *it)
			return 0;
		a = *it;
		it++;
	}
	return 1;
}

void PmergeMe::print(bool val)
{
	if (val == true)
		std::cout << BLEU << "Before: " << REINIT;
	else
		std::cout << VERT << "After: " << REINIT;
	std::vector<int>::iterator it = this->_vector.begin();
	while (it != this->_vector.end())
	{
		if (val == true)
			std::cout << BLEU << *it << REINIT;
		else
			std::cout << VERT << *it << REINIT;
		if (it + 1 != this->_vector.end())
			std::cout << " ";
		it++;
	}
	std::cout << std::endl;
}

 /* +++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++ Init containers +++++++++++++++++++ */
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
 /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++++++++++++++++ Execution ++++++++++++++++++++++++++ */

void PmergeMe::fordJohnsonSort(std::vector<int>& arr)
{
	if (arr.size() <= 1)
        return;
	int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());
    fordJohnsonSort(left);
    fordJohnsonSort(right);
    arr.clear();
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(arr));
}



void PmergeMe::Run(void)
{
	print(1);
	if (alreadySorted())
		std::cout << VERT << "After:  already sorted" << REINIT << std::endl;
	else
	{
		fordJohnsonSort(this->_vector);
		print(0);
	}
}

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++ */