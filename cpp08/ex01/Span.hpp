#ifndef SPAN_HPP
	#define SPAN_HPP

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
	public:
	//coplian form
	Span(unsigned int n);
	Span(const Span &other);
	~Span();
	Span &operator=(const Span &other);

	void addNumber(int n);
	int shortestSpan(void);
	int longestSpan(void);
	const std::vector<int> *getVector(void) const;

	
	private:
	Span(void){};
	std::vector<int> _vector;
	unsigned int _n;

};

std::ostream &operator<<(std::ostream &os, const Span &sp);


#endif