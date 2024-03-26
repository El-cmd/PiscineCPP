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
	BitcoinConverter(std::string input);
	//BitcoinConverter(const BitcoinConverter &other);
	//BitcoinConverter &operator=(const BitcoinConverter &other);

	//getter

	//Member Functions

	private:
	BitcoinConverter();
	std::map<std::string, std::string> _data;
	std::map<std::string, std::string> _input;
};




#endif