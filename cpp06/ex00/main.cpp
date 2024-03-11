#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter::convert(av[1]);
        return EXIT_SUCCESS;
    }
    std::cout << "Le programme ScalerConverter ne peut convertir qu'un parametre" << std::endl;
    return EXIT_FAILURE;
}