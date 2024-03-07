#include "ScalarConverter.hpp"


int main(int ac, char **av)
{
    if (av == 2)
    {
        ScalarConverter::convert(av[1]);
        return 0;
    }
    else if
        std::cout << "Le programme ScalerConverter ne peut convertir qu'un parametre" << std::endl;
    return 1;
}