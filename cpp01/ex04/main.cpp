#include <iostream>
#include <fstream>
#include <string>
#include "sed2.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        Sed sedatif(av);
        if(!sedatif.doSed())
            return (-1);
        else
            std::cout << "\e[92;5;118mYour .replace is ready.\n\e[0m";
    }
    else {
        std::cout << "Bad arguments !" << std::endl;
		std::cout << "Usage : file, S1, S2 !" << std::endl;
        return (-1);
    }
    return 0;
}