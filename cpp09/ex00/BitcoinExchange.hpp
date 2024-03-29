#ifndef BITCOINEXCHANGE_HPP
	#define BITCOINEXCHANGE_HPP


#include <exception>
#include <string>
#include <iostream>
#include <map>
#include <fstream>


class BitcoinConverter
{
	public:
	// Coplien
	BitcoinConverter(const std::string &input);
	void initBdd(void);
	void initInput(const std::string &input);
	std::map<std::string, std::string> &getInput();
	std::map<std::string, std::string> &getData();
	//BitcoinConverter(const BitcoinConverter &other);
	//BitcoinConverter &operator=(const BitcoinConverter &other);

	//getter

	//Member Functions

	private:
	BitcoinConverter();
	std::map<std::string, std::string> _data;
	std::map<std::string, std::string> _input;
};

void print(const std::map<std::string, std::string> &input);



#endif