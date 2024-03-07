#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

void pseudo_litteral(std::string string)
{
    if (string == "-inff" || string == "+inff")
        return ;
    else if (string == "+inf" || string "-inf" || string == "nan")
        return ;
}

void ScalarConverter::convert(std::string toConvert)
{

}
