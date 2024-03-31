#ifndef BITCOINEXCHANGE_HPP
	#define BITCOINEXCHANGE_HPP



#include <exception>
#include <string>
#include <iostream>
#include <map>
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
	// Coplien
	BitcoinConverter(const std::string &input);
	const std::multimap<std::string, std::string> &getInput();
	const std::map<std::string, std::string> &getData();
	//BitcoinConverter(const BitcoinConverter &other);
	//BitcoinConverter &operator=(const BitcoinConverter &other);

	//getter
	void initBdd(void);
	void initInput(const std::string &input);
	void checkFloat(void);

	//Member Functions
	private:
	BitcoinConverter();
	std::map<std::string, std::string> _data;
	std::multimap<std::string, std::string> _input;
};

void print(const std::multimap<std::string, std::string> &input); // Ne pas oublier de la suppr
std::string trim(const std::string& str);



#endif