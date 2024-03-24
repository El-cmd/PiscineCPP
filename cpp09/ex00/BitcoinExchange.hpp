#ifndef BITCOINEXCHANGE_HPP
	#define BITCOINEXCHANGE_HPP


#include <exception>
#include <string>
#include <iostream>
#include <map>


class BitcoinConverter
{
	public:
	// Coplien
	BitcoinConverter(std::string input);
	BitcoinConverter(const BitcoinConverter &other);
	BitcoinConverter &operator=(const BitcoinConverter &other);

	//getter

	//Member Functions

	private:
	BitcoinConverter();
	std::map<std::string, float> data;
	std::map<std::string, float> input;
};


#endif