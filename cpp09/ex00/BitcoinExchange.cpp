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
	else
		throw std::logic_error("No data.csv in this folder");
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

// ++++++++++ Securité ++++++++ //

float BitcoinConverter::protectStrtof(const char *strIt)
{
	char *endptr;
	float result = std::strtof(strIt, &endptr);
	float a = -1;
	if ((endptr == strIt) || (*endptr != '\0') || (errno == ERANGE && (result == FLT_MAX || result == -FLT_MAX)) \
		|| (errno == ERANGE && result == 0))
        return a;
	return result;
}

int BitcoinConverter::protectDate(const std::string &date)
{
	if (date.size() != 10)
	{
		std::cerr << ROUGE << "Error Bad input => " << date << REINIT << std::endl;
		return 1;
	}
	std::string Year;
	std::string Month;
	std::string Day;
	int i = 0;
	int delim = 0;
	while (date[i])
	{
		if (delim == 0)
			Year = Year + date[i];
		else if (delim == 1)
			Month = Month + date[i];
		else if ( delim == 2)
			Day = Day + date[i];
		if (date[i] == '-')
			delim++;
		i++;
	}
	if (delim != 2 || (Month < "01" || Month > "13") || (Day < "01" || Day > "31") || (Year > "2023"))
	{
		std::cerr << ROUGE << "Error Bad input => " << date << REINIT << std::endl;
		return 1;
	}
	return 0;
}


// +++++++++++++++++++++++++ execution ++++++++++++++++++++++++++++++++++++++ //
float  BitcoinConverter::Compare(const std::string &date, const float &Float)
{
	std::map<std::string, std::string>::iterator it = this->_data.begin();
	std::map<std::string, std::string>::iterator ite = this->_data.end();
	ite --;
	if (it->first > date)
		return Float * protectStrtof(it->second.c_str());
	if (ite->first < date)
		return Float * protectStrtof(ite->second.c_str());
	while (it->first < date && it != _data.end())
		it++;
	if (it->first == date)
		return Float * protectStrtof(it->second.c_str());
	else
		it--;
	return Float * protectStrtof(it->second.c_str());
}

void BitcoinConverter::printResult(const float &Float, const std::string &Date)
{
	if (protectDate(Date))
		return ;
	float result = this->Compare(Date, Float);
	if (result == -1)
			std::cerr << ROUGE << "Error: Invalid number" << REINIT << std::endl;
	else if (Float < 0)
		std::cerr << ROUGE << "Error: not a positive number" << REINIT <<std::endl;
	else if (Float > 1000)
		std::cerr << ROUGE << "Error: too large number" << REINIT << std::endl;
	else
			std::cout << Date << " => " << Float << " = " << result << std::endl;
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
			if (i != std::string::npos)
			{
				date = trim(buff.substr(0, i));
				valeur = trim(buff.substr(i + 1, buff.size()));
				this->printResult(std::strtof(valeur.c_str(), NULL), date);
			}
			else
				std::cerr << ROUGE << "Error: Invalid line" << REINIT << std::endl;
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
std::string BitcoinConverter::trim(const std::string& str) 
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ //

