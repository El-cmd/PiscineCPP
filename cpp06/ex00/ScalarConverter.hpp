#ifndef SCALARCONVERTER_HPP
    #define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
    private:
    ScalarConverter();

    public:
    convert(std::string toConvert);
    toChar(std::string toConvert);
    toInt(std::string toConvert);
    toFloat(std::string toConvert);
    toDouble(std::string toConvert);
    
};


#endif