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
	int sign = 0;
	int nb = 0;
	while (i >= 0)
	{
		if (isdigit(tmp[i]))
		{
			this->_stack.push(tmp[i] - '0');
			nb++;
		}
		else if (isSign(tmp[i]))
		{
			this->_stack.push(tmp[i]);
			sign++;
		}
		i--;
	}
	if (!(sign + 1 == nb))
		throw std::logic_error("needs one more digit than sign");
}
/* +++++++++++++++++++++++++++ */

/* ++++++ Execution +++++ */

float RPN::calcul(float a, float b, char c)
{
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
	int tmp;
	float result2;
	std::stack<int> _prio;
	float result = this->_stack.top();
	this->_stack.pop();
	tmp = this->_stack.top();
	this->_stack.pop();
	result = calcul(result, tmp, this->_stack.top());
	this->_stack.pop();
	while(!this->_stack.empty())
	{
		tmp = this->_stack.top();
		if (isSign(tmp))
			throw std::logic_error("Error sign");
		this->_stack.pop();
		if (isSign(this->_stack.top()))
		{
			if (isSign(tmp))
				throw std::logic_error("Error sign");
			result = calcul(result, tmp, this->_stack.top());
			this->_stack.pop();
		}
		else
		{
			while (!isSign(this->_stack.top()))
			{
				_prio.push(this->_stack.top());
				this->_stack.pop();
			}
			result2 = _prio.top();
			_prio.pop();
			while (!_prio.empty())
			{
				result2 = calcul(result2, _prio.top(), this->_stack.top());
				this->_stack.pop();
				_prio.pop();
			}
			result2 = calcul(tmp, result2, this->_stack.top());
			this->_stack.pop();
			result = calcul(result, result2, this->_stack.top());
			this->_stack.pop();
		}
	}
	std::cout << VERT << result << REINIT << std::endl;
}

/* +++++++++++++++++++++++ */