#ifndef BITCOINEXCHANGE_HPP
	#define BITCOINEXCHANGE_HPP

#include <exception>
#include <string>
#include <iostream>
#include <map>
#include <cfloat>
#include <fstream>
#include <cctype>
#include <cstdlib>

// Color ->
#define REINIT "\033[0m"
#define NOIR "\033[30m"
#define ROUGE "\033[31m"
#define VERT "\033[32m"
#define JAUNE "\033[33m"
#define BLEU "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BLANC "\033[37m" 

class BitcoinConverter
{
	public:

	//Constructor && destructor
	BitcoinConverter(const std::string &input);
	~BitcoinConverter(){};
	//Exec Function
	void Run(void);

	private:
	//getter
	const std::string &getInput(void);
	const std::map<std::string, std::string> &getData(void);

	// Coplien
	BitcoinConverter &operator=(const BitcoinConverter &other);
	BitcoinConverter(const BitcoinConverter &other);
	BitcoinConverter(void);

	//Member Functions
	int protectDate(const std::string &date);
	float protectStrtof(const char *strIt);
	void initBdd(void);
	void printResult(const float &Float, const std::string &Date);
	float  Compare(const std::string &date, const float &Float);
	std::string trim(const std::string& str);

	std::map<std::string, std::string> _data;
	const std::string _input; 
};

#endif