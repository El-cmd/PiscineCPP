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
#include <utility>
#include <ctime>


class PmergeMe
{
	public:
	/* ++++++++ constructor && destructor ++++++*/
	PmergeMe(const std::string &av);
	~PmergeMe(void);
	/*++++++++++++++++++++++++++++++++++++++++++*/
	void print(bool val); // affiche false _vector/true _list 
	void Run(void); // Lance le tri

	private:

	/*++++++++++++++ Coplien Form ++++++++++++++*/
	PmergeMe &operator=(const PmergeMe &other);
	PmergeMe(const PmergeMe &other);
	PmergeMe(void);
	/*++++++++++++++++++++++++++++++++++++++++++*/
	/*++++++++++++Algorithme+++++++++++++++++++*/
	/* Vector */
	std::vector<std::pair<int, int> > makeBigPairV(std::vector<int>& arr);
	void littleInsertV(std::vector<std::pair<int, int> > &_pair, int imp);
	void fordJohnsonSortFor_vector(std::vector<int>& arr);
	void bigSortV(std::vector<std::pair<int, int> > &pair);
	/* List */
	std::list<std::pair <int, int> > makeBigPairL(std::list<int> &list);
	void littleInsertL(std::list <std::pair <int, int> > &pair, int tmp);
	void fordJohnsonSortFor_list(std::list<int> &list);
	void bigSortL(std::list<std::pair <int, int> > &list);

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