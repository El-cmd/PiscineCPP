#include "BitcoinExchange.hpp"

// +++++++++++++++++++++++++++ Constructeur +++++++++++++++++++++++++++++++++ //
BitcoinConverter::BitcoinConverter(const std::string &input): _input(input)
{
	this->initBdd();
}

BitcoinConverter::BitcoinConverter(void)
{
	std::cout << "Default constructor called" << std::endl;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

// ++++++++++++++++++ Base de données dans la map +++++++++++++++++++++++++++ //
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
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //


// +++++++++++++++++++++++++ execution ++++++++++++++++++++++++++++++++++++++ //
float  BitcoinConverter::Compare(const std::string &date, const float &Float)
{
	float result;
	std::map<std::string, std::string>::iterator it = this->_data.begin();
	while (it->first < date && it != _data.end())
		it++;
	result = Float * std::strtof(it->second.c_str(), NULL);
	if (it->first == date)
		return result;
	else
		it--;
	result = Float * std::strtof(it->second.c_str(), NULL);
	return result;
}

void BitcoinConverter::printResult(const float &Float, const std::string &Date)
{
	if (Float < 0)
		std::cerr << ROUGE << "Error: not a positive number" << REINIT <<std::endl;
	else if (Float > 1000)
		std::cerr << ROUGE << "Error: too large number" << REINIT <<std::endl;
	else
		std::cout << Date << " => " << Float << " = " << this->Compare(Date, Float) << std::endl;
}

void BitcoinConverter::Run(void)
{
	std::ifstream inn(this->_input.c_str());
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
			this->printResult(std::strtof(valeur.c_str(), NULL), date);
		}
		inn.close();
	}
	else
		throw std::invalid_argument("Invalid file");
}

// ++++++++++++++++++++++++ getter +++++++++++++++++++++++++++++++++++++++ //
const std::map<std::string, std::string> &BitcoinConverter::getData(void)
{
	return this->_data;
}

const std::string &BitcoinConverter::getInput(void)
{
	return this->_input;
}
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

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

