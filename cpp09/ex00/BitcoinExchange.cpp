#include "BitcoinExchange.hpp"


void	BitcoinConverter::initBdd(void)
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
	if (!input.empty())
		throw std::invalid_argument("Input is empty");
	std::ifstream in(input);
	std::string buff;
	std::string date;
	std::string valeur;
	size_t i;
	if (in)
	{
		getline(in, buff); //enleve la premiere string
		while (getline(in, buff))
		{
			i = buff.find("|");
			date = buff.substr(0, i);
			valeur = buff.substr(i + 1, buff.size());
			_data[date] = valeur;
		}
		in.close();
	}
}

BitcoinConverter::BitcoinConverter(const std::string &input)
{
	(void) input;
	this->initBdd();

}

BitcoinConverter::BitcoinConverter(void)
{
	std::cout << "Default constructor called" << std::endl;
}