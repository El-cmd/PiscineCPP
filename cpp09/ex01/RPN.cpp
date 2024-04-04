#include "RPN.hpp"

/*+++++++++ Coplian Form ++++++++++++++++*/

RPN::RPN()
{
	std::cout << "Default Constructor called" << std::endl;
}

RPN::RPN(const std::string &av)
{
	secureAv(av);
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{

	}
	return *this;
}

/*++++++++++++++++++++++++++++++++++++++++*/


/* +++++ Gestion erreur +++++ */

void RPN::secureAv(const std::string &av)
{
	if (av.empty())
		throw std::invalid_argument("Arguments is empty");
}