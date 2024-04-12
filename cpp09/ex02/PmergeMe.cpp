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
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		*this = other;
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
	for (size_t i = 1; i < tmp.size(); ++i)
        if (tmp[i - 1] == tmp[i])
            throw std::logic_error("No same numbers"); // Doublon trouvé
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

/*++++++++++++Algorithme For vector +++++++++++++++++++*/
void PmergeMe::bigSortV(std::vector<std::pair<int, int> > &pair)
{
	std::vector<std::pair<int, int> >::iterator it = pair.begin();
	std::vector<std::pair<int, int> >::iterator itt = pair.begin() + 1;
	while (itt != pair.end())
	{
		if (it->first > itt->first)
		{
			std::swap(it->first, itt->first);
			it = pair.begin();
			itt = pair.begin() + 1;
		}
		it++;
		itt++;
	}
	it = pair.begin();
	while (it != pair.end())
	{
		this->_vector.push_back(it->first);
		it++;
	}
}

std::vector<std::pair<int, int> > PmergeMe::makeBigPairV(std::vector<int>& arr)
{
	std::vector<std::pair<int, int> > _pair;
	int tmp;
	std::vector<int>::iterator it = arr.begin();
	while (it != arr.end())
	{
		tmp = *it;
		it++;
		if (tmp > *it)
			_pair.push_back(std::make_pair(tmp, *it));
		else
			_pair.push_back(std::make_pair(*it, tmp));
		it++;
	}
	return _pair;
}

void PmergeMe::littleInsertV(std::vector<std::pair<int, int> > &_pair, int imp)
{
	std::vector<std::pair<int, int> >::iterator itt = _pair.begin();
	std::vector<int>::iterator it = this->_vector.begin();
	while (itt != _pair.end())
	{
		while (itt->second > *it)
			it++;
		if (itt->second < *it)
		{
			this->_vector.insert(it, 1, itt->second);
			it = this->_vector.begin();
		}
		itt++;
	}
	if (imp != -1)
	{
		it = this->_vector.begin();
		while (imp > *it)
			it++;
		this->_vector.insert(it, 1, imp);
	}
}

void PmergeMe::fordJohnsonSortFor_vector(std::vector<int>& arr)
{
	int imp = -1;
	if (arr.size() % 2 != 0)
	{
		imp = arr.back();
		arr.pop_back();
	}
	std::vector<std::pair<int, int> > _pair = makeBigPairV(arr);
	arr.clear();
	bigSortV(_pair);
	littleInsertV(_pair, imp);
}
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/*++++++++++++Algorithme For list +++++++++++++++++++*/
void PmergeMe::bigSortL(std::list<std::pair<int, int> > &pair)
{
	std::list<std::pair<int, int> >::iterator it = pair.begin();
	std::list<std::pair<int, int> >::iterator itt = pair.begin();
	itt++;
	while (itt != pair.end())
	{
		if (it->first > itt->first)
		{
			std::swap(it->first, itt->first);
			it = pair.begin();
			itt = pair.begin();
			itt++;
		}
		it++;
		itt++;
	}
	it = pair.begin();
	while (it != pair.end())
	{
		this->_list.push_back(it->first);
		it++;
	}
}

std::list<std::pair<int, int> > PmergeMe::makeBigPairL(std::list<int>& arr)
{
	std::list<std::pair<int, int> > _pair;
	int tmp;
	std::list<int>::iterator it = arr.begin();
	while (it != arr.end())
	{
		tmp = *it;
		it++;
		if (tmp > *it)
			_pair.push_back(std::make_pair(tmp, *it));
		else
			_pair.push_back(std::make_pair(*it, tmp));
		it++;
	}
	return _pair;
}

void PmergeMe::littleInsertL(std::list<std::pair<int, int> > &_pair, int imp)
{
	std::list<std::pair<int, int> >::iterator itt = _pair.begin();
	std::list<int>::iterator it = this->_list.begin();
	while (itt != _pair.end())
	{
		while (itt->second > *it)
			it++;
		if (itt->second < *it)
		{
			this->_list.insert(it, 1, itt->second);
			it = this->_list.begin();
		}
		itt++;
	}
	if (imp != -1)
	{
		it = this->_list.begin();
		while (imp > *it)
			it++;
		this->_list.insert(it, 1, imp);
	}
}

void PmergeMe::fordJohnsonSortFor_list(std::list<int>& arr)
{
	int imp = -1;
	if (arr.size() % 2 != 0)
	{
		imp = arr.back();
		arr.pop_back();
	}
	std::list<std::pair<int, int> > _pair = makeBigPairL(arr);
	arr.clear();
	bigSortL(_pair);
	littleInsertL(_pair, imp);
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* +++++++++++++++++++++ Exec ++++++++++++++++++++++++++++++ */
void PmergeMe::Run(void)
{
	print(1);
	if (alreadySorted())
		std::cout << VERT << "After:  already sorted" << REINIT << std::endl;
	else
	{
		timespec start, end;
		clock_gettime(CLOCK_MONOTONIC, &start);
		fordJohnsonSortFor_vector(this->_vector);
		clock_gettime(CLOCK_MONOTONIC, &end);
		print(0);
		long sec = end.tv_sec - start.tv_sec;
    	long nsec = end.tv_nsec - start.tv_nsec;
    	long micros = sec * 1000000 + nsec / 1000; 
		std::cout << JAUNE << "Time to process a range of " << this->_vector.size();
		std::cout << JAUNE << " elements with std::vector<int> : " << micros << " us" << REINIT <<std::endl;
		clock_gettime(CLOCK_MONOTONIC, &start);
		fordJohnsonSortFor_list(this->_list);
		clock_gettime(CLOCK_MONOTONIC, &end);
		sec = end.tv_sec - start.tv_sec;
    	nsec = end.tv_nsec - start.tv_nsec;
    	micros = sec * 1000000 + nsec / 1000; 
		std::cout << JAUNE << "Time to process a range of " << this->_list.size();
		std::cout << JAUNE << " elements with std::list<int> : " << micros << " us" << REINIT <<std::endl;
	}
}
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++ */