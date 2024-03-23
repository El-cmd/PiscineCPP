#ifndef MUTANTSTACK_HPP
	#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <deque>


template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	MutantStack(void) { };
	~MutantStack() {} ;
	MutantStack(const MutantStack &other) { *this = other; };
	MutantStack &operator=(const MutantStack &other)
	{
		std::stack<T, Container>::operator=(other);
		return *this;
	};

	typename Container::iterator begin()
	{
		return this->c.begin();
	}
	typename Container::iterator end()
	{
		return this->c.end();
	}

	const_iterator begin() const 
	{
		return this->c.begin();
	}

	const_iterator end() const 
	{
		return this->c.end();
	}
}; 

#endif 