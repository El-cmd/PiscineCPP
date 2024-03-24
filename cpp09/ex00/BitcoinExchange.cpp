#include "BitcoinExchange.hpp"

BitcoinConverter::BitcoinConverter(std::string input)
{
	std::ifstream in("data.csv");
	std::string data_line;
	if (in)
	{
		while (getline(in, data_line))
		{
			
		}
	}

}