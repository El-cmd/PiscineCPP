#ifndef RPN__HPP
	#define RPN__HPP


//color
#define REINIT "\033[0m"
#define NOIR "\033[30m"
#define ROUGE "\033[31m"
#define VERT "\033[32m"
#define JAUNE "\033[33m"
#define BLEU "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BLANC "\033[37m" 

#include <string>
#include <iostream>
#include <exception>
#include <list>


class RPN
{
	public:
	/* +++ Coplien Form +++ */
	RPN(const std::string &av);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);


	private:
	/* ++++++ Members functions ++++++*/
	void secureAv(const std::string &av);
	
	std::list<int> _Liste;
	RPN();
};

#endif