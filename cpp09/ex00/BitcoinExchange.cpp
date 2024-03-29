#include "BitcoinExchange.hpp"


void BitcoinConverter::initBdd(void)
{
	std::ifstream in("data.csv");
	std::string buff;
	std::string date;
	std::string valeur;
	size_t i;
	if (in)
	{
		getline(in, buff); //enleve la premiere string
		while (getline(in, buff))
		{
			i = buff.find(",");
			date = buff.substr(0, i);
			valeur = buff.substr(i + 1, buff.size());
			_data[date] = valeur;
		}
		in.close();
	}
}

void BitcoinConverter::initInput(const std::string &input)
{
	if (input.empty())
		throw std::invalid_argument("Input is empty");
	std::ifstream inn(input.c_str());
	std::string buff;
	std::string date;
	std::string valeur;
	size_t i;
	if (inn)
	{
		//getline(inn, buff); //enleve la premiere string
		while (getline(inn, buff))
		{
			i = buff.find("|");
			date = buff.substr(0, i);
			valeur = buff.substr(i + 1, buff.size());
			_input[date] = valeur;
		}
		inn.close();
	}
}


std::map<std::string, std::string> &BitcoinConverter::getInput()
{
	return this->_input;
}

std::map<std::string, std::string> &BitcoinConverter::getData()
{
	return this->_data;
}


void print(const std::map<std::string, std::string> &input)
{
	int i = 0;
	std::map<std::string, std::string>::const_iterator it = input.begin();
	while (it != input.end())
	{
		std::cout << i << std::endl;
		std::cout << it->first << "===>" << it->second << std::endl;
		it++;
		i++;
	}
}


BitcoinConverter::BitcoinConverter(const std::string &input)
{
	this->initInput(input);
	this->initBdd();
}

BitcoinConverter::BitcoinConverter(void)
{
	std::cout << "Default constructor called" << std::endl;
}