#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR;
    std::string &stringREF = str;
    stringPTR = &str;
    std::cout << "L'adress de str: " << &str << std::endl;
    std::cout << "L'adresse de stringPTR: " << stringPTR << std::endl;
    std::cout << "L'adresse de stringREF: " << &stringREF << std::endl; 
    std::cout << "La valeur de str: " << str << std::endl;
    std::cout << "La valeur pointé par stringPTR: " << *stringPTR << std::endl;
    std::cout << "La valeur pointé par stringREF: " << stringREF << std::endl;
    return 0;
}