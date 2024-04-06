#ifndef PMERGEME_HPP
	#define PMERGEME_HPP

//colors
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
#include <vector>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <list>
#include <algorithm>

class PmergeMe
{
	public:
	/* ++++++++ constructor && destructor ++++++*/
	PmergeMe(const std::string &av);
	~PmergeMe(void);
	/*++++++++++++++++++++++++++++++++++++++++++*/
	void printBefore(bool val); // affiche false _vector/true _list 
	void Run(void);

	private:

	/*++++++++++++++ Coplien Form ++++++++++++++*/
	PmergeMe &operator=(const PmergeMe &other);
	PmergeMe(const PmergeMe &other);
	PmergeMe(void);
	/*++++++++++++++++++++++++++++++++++++++++++*/
	std::string secureAv(const std::string &av);
	std::string trim(const std::string& str);
	void initContainers(std::string tmp);
	void secureDouble(void);
	int alreadySorted(void);
	std::vector<int> _vector;
	std::list<int> _list;
};


#endif