#include "RPN.hpp"

/*+++++++++ Coplian Form ++++++++++++++++*/

RPN::RPN()
{}

RPN::RPN(const std::string &av)
{
	initQueue(secureAv(av));
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		*this = other;
	return *this;
}

RPN::~RPN(void)
{}

/*++++++++++++++++++++++++++++++++++++++++*/

/* +++++++++++Utils functions ++++++++++++*/
bool RPN::isSign(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

std::string RPN::trim(const std::string& str) 
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
/*++++++++++++++++++++++++++++++++++++++++*/

/* +++++ Gestion erreur +++++ */
std::string RPN::secureAv(const std::string &av)
{
	std::string tmp;
	int i = 0;
	tmp = trim(av);
	if (tmp.empty())
		throw std::invalid_argument("Argument is empty");
	if ((!isdigit(tmp[0]) || !isdigit(tmp[2])) || !isSign(tmp[tmp.length() - 1]))
		throw std::invalid_argument("Not a valid input");
	while (tmp[i])
	{
		if (isspace(tmp[i]) || isdigit(tmp[i]) || isSign(tmp[i]))
		{
			if (isdigit(tmp[i]) && !isspace(tmp[i + 1]))
				throw std::invalid_argument("Only number between 0 and 9");
			i++;
		}
		else
			throw std::invalid_argument("Not a valid input");
	}
	return (tmp);
}

/* ++++++ Init data ++++++++++ */
void RPN::initQueue(std::string tmp)
{
	int i = tmp.length() - 1;
	while (i >= 0)
	{
		if (isdigit(tmp[i]))
			this->_stack.push(tmp[i] - '0');
		else if (isSign(tmp[i]))
			this->_sign.push(tmp[i]);
		i--;
	}
}
/* +++++++++++++++++++++++++++ */

/* ++++++ Execution +++++ */

int RPN::calcul(int a, int b, char c)
{
	// if (this->_stack.empty() && !this->_sign.empty())
		// return a;
	if (c == SOUS)
		return a - b;
	else if (c == ADD)
		return a + b;
	else if (c == MULT)
		return a * b;
	else if (c == DIV)
	{
		if (b == 0)
			throw std::logic_error("No division by zero");
		else
			return a / b;
	}
	return a;
}

void RPN::Run(void)
{
	int result;
	result = this->_stack.top();
	this->_stack.pop();
	while(!this->_sign.empty() && !this->_stack.empty())
	{
		result = calcul(result, this->_stack.top(), this->_sign.top());
		this->_sign.pop();
		this->_stack.pop();
	}
	std::cout << VERT << result << REINIT << std::endl;
}

/* +++++++++++++++++++++++ */