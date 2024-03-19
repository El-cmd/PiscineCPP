#include "Span.hpp"

Span::Span(unsigned int n): _n(n)
{
	std::cout << "Default constructor called" << std::endl;
}

Span::Span(const Span &other)
{
	if (this != &other)
	{
		this->_n = other._n;
		this->_vector = other._vector;
	}
}

Span::~Span()
{
	std::cout << "Default constructor called" << std::endl;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_n = other._n;
		this->_vector = other._vector;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_vector.size() < this->_n)
		this->_vector.push_back(n);
	else
		throw std::out_of_range("No place for more number\n");
}

const std::vector<int> *Span::getVector(void) const
{
	return &_vector;
}

int Span::shortestSpan(void)
{
	if (_vector.size() < 2)
		throw std::logic_error("Pas assez d'entier dans le tableau\n");
	std::vector<int>::iterator it = _vector.begin();
	std::vector<int>::iterator it2 = _vector.begin();
	int max = longestSpan();
	while (it != _vector.end())
	{
		while (it2 != _vector.end())
		{
			if (it2 == it)
				it2++;
			if (max > *it2 - *it)
				max = *it2 - *it;
			it2++;
		}
		it++;
	}
	if (max < 0)
		max *= -1;
	return max;
}

int Span::longestSpan(void)
{
	if (_vector.size() >= 2)
		return (*std::max_element( _vector.begin(), _vector.end() )) - (*std::min_element( _vector.begin(), _vector.end() ));
	throw std::logic_error("Pas assez d'entier dans le tableau\n");
}


std::ostream &operator<<(std::ostream& os,const Span &sp)
{
	std::vector<int>::const_iterator it = sp.getVector()->begin();
	while (it != sp.getVector()->end())
	{
		os << *it << std::endl;
		it++;
	}
	return os;
}
