#include "ScalarConverter.hpp"

#define CI "char: impossible\n"
#define II "int: impossible\n"
#define FI "float: impossible\n"
#define DI "double: impossible\n"

#define C "char: "
#define I "int: "
#define F "float: "
#define D "double: "

#define IS_C 1
#define IS_I 2
#define IS_F 3
#define IS_D 4

#define ERR -1


int pseudo_litteral(const std::string &string)
{
    float positiveInFfinity = INFINITY; //+inff
    float negativeInFfinity = -INFINITY; //-inff
    float positiveInfinity = std::numeric_limits<float>::infinity(); //+inf
    float negativeInfinity = -std::numeric_limits<float>::infinity(); //-inf 
    double nanValue = std::numeric_limits<double>::quiet_NaN(); //nan
    float nanfValue = std::numeric_limits<float>::quiet_NaN();

    if (string == "nanf" || string == "-inff" || string == "+inff" || string == "+inf" || string == "-inf" || string == "nan")
    {
        std::cout << CI << II;
        if (string == "+inf")
        {
            std::cout << F << positiveInfinity << std::endl;
            std::cout << D << static_cast<double>(positiveInfinity) << std::endl;

        }
        if (string == "-inf")
        {
            std::cout << F << negativeInfinity << std::endl;
            std::cout << D << static_cast<double>(negativeInfinity) << std::endl;
        }
        if (string == "+inff")
        {
            std::cout << F << positiveInFfinity << std::endl;
            std::cout << D << static_cast<double>(positiveInFfinity) << std::endl;
        }
        if (string == "-inff")
        {
            std::cout << F << negativeInFfinity << std::endl;
            std::cout << D << static_cast<double>(negativeInFfinity) << std::endl;
        }
        if (string == "nan")
        {
            std::cout << F << static_cast<float>(nanValue) << std::endl; // double to float
            std::cout << D << nanValue << std::endl;
        }
        if (string == "nanf")
        {
            std::cout << F << nanfValue << std::endl;
            std::cout << D << static_cast<double>(nanfValue) << std::endl;  //float to double
        }
        return 1;
    }
    return 0;
}

int detected(const std::string &toDetect)
{
    int i = 0;
    if (toDetect.size() == 1 && !isdigit(toDetect[0]) && isprint(toDetect[0]))
        return IS_C; //char
    for ( ;toDetect[i] == '-' || toDetect[i] == '+'; ) i++;
    if (!toDetect[i])       //GESTION DERREUR       
        return (ERR);       //GESTION DERREUR
    for ( ;isdigit(toDetect[i]); ) i++;
    if (!toDetect[i])
        return IS_I; //int
    else if (toDetect[i] == 'f')
        return IS_F; //float
    else if (toDetect[i] == '.')
    {
        i++;
        if (!toDetect[i])       //GESTION DERREUR
            return ERR;     //GESTION DERREUR
        for ( ;isdigit(toDetect[i]);) i++;
        if (!toDetect[i])
            return IS_D;    //double
        else if (toDetect[i] == 'f')
            return IS_F; // float
    }
    return ERR;
}

void toChar(const std::string &string)
{
    char c = string[0];
    std::cout << C << c << std::endl;  
    std::cout << I << static_cast<int>(c) << std::endl;
    std::cout << F << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << D << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;

}

void toInt(const std::string &string)
{
    long i = atol(string.c_str());
    if (i > INT_MAX || i < INT_MIN)
    {
        std::cout << CI << II << FI << DI;
        return ;
    }
    else if (i > CHAR_MAX || i < CHAR_MIN)
        std::cout << CI;
    else if (!isprint(i))
        std::cout << C << "Non displayable\n";
    else
        std::cout << C << static_cast<char>(i) << std::endl;
    std::cout << I << i << std::endl;
    std::cout << F << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
    std::cout << D << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void toFloat(const std::string &string)
{
    float Float = std::strtof(string.c_str(), NULL);
    if (Float > static_cast<float>(CHAR_MAX) || Float < static_cast<float>(CHAR_MIN))
        std::cout << CI;
    else if (!isprint(roundf(Float)))
        std::cout << C << "Non displayable" << std::endl;
    else
    {
        char c = static_cast<char>(Float);
        std::cout << C << c << std::endl;
    }
    if (Float < static_cast<float>(INT_MIN) || Float > static_cast<float>(INT_MAX))
        std::cout << II;
    else
    {
        int i = static_cast<int>(Float);
        std::cout << I << i << std::endl;
    }
    std::cout << std::fixed << std::setprecision(1) << F << Float << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << D << static_cast<double>(Float) << std::endl;
}

void toDouble(const std::string &string)
{
    double Double = std::strtod(string.c_str(), NULL);
    if (Double > static_cast<double>(CHAR_MAX) || Double < static_cast<double>(CHAR_MIN))
        std::cout << CI;
    else if (!isprint(roundf(Double)))
        std::cout << C << "Non displayable" << std::endl;
    else
    {   
        char c = static_cast<char>(roundf(Double));
        std::cout   << C << c << std::endl;
    }
    if (Double > static_cast<double>(INT_MAX) || Double < static_cast<double>(INT_MIN))
        std::cout << II;
    else
        std::cout << I <<  static_cast<int>(roundf(Double)) << std::endl;
    if (Double > static_cast<double>(__FLT_MAX__) || Double < static_cast<double>(-__FLT_MAX__))
        std::cout << FI;
    else
        std::cout << F << std::fixed << std::setprecision(1) << static_cast<float>(Double) << "f" << std::endl;
    std::cout << D << std::fixed << std::setprecision(1) << Double << std::endl;
}

void ScalarConverter::convert(const std::string &toConvert)
{
    if (pseudo_litteral(toConvert))
        return ;
    switch (detected(toConvert))
    {
        case (IS_C):
            toChar(toConvert);
            break;
        case (IS_I):
            toInt(toConvert);
            break;
        case (IS_D):
            toDouble(toConvert);
            break;
        case (IS_F):
            toFloat(toConvert);
            break;
        default:
            break;
    }
    
}
