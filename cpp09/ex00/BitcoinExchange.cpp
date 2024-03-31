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
			this->_data[date] = valeur;
		}
		in.close();
	}
}

void BitcoinConverter::initInput(const std::string &input)
{
	std::ifstream inn(input.c_str());
	std::string buff;
	std::string date;
	std::string valeur;
	size_t i = 0;
	if (inn)
	{
		getline(inn, buff); //enleve la premiere string
		while (getline(inn, buff))
		{
			i = buff.find("|");
			date = trim(buff.substr(0, i));
			valeur = trim(buff.substr(i + 1, buff.size()));
			this->_input.insert(std::make_pair(date, valeur)); //fait des clefs.valeurs pour le multimap 
		}
		inn.close();
	}
	else
		throw std::invalid_argument("Invalid file");
}

const std::multimap<std::string, std::string> &BitcoinConverter::getInput()
{
	return this->_input;
}

const std::map<std::string, std::string> &BitcoinConverter::getData()
{
	return this->_data;
}

void BitcoinConverter::checkFloat(void)
{
	float tmp;
	std::multimap<std::string, std::string>::const_iterator it = this->_input.begin();
	while (it != this->_input.end())
	{
		tmp = std::strtof(it->second.c_str(), NULL);
		if (tmp < 0)
			std::cerr << ROUGE << "Invalid => No negative number" << REINIT <<std::endl;
		it++;
	}

}

// +++++++++++++++++++++++++ Fonction à supprimer +++++++++++++++++++++++++++ //
void print(const std::multimap<std::string, std::string> &input) //Pour print une mutlimap
{
	std::multimap<std::string, std::string>::const_iterator it = input.begin();
	while (it != input.end())
	{
		std::cout << it->first << "===>" << it->second << std::endl;
		it++;
	}
}

// Fonction pour élaguer les espaces blancs au début et à la fin d'une chaîne
std::string trim(const std::string& str) 
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

// +++++++++++++++++++++++++++ Constructeur +++++++++++++++++++++++++++++++++ //
BitcoinConverter::BitcoinConverter(const std::string &input)
{
	this->initInput(input);
	this->initBdd();
	this->checkFloat();
}

BitcoinConverter::BitcoinConverter(void)
{
	std::cout << "Default constructor called" << std::endl;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //
