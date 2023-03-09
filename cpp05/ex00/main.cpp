#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Doc", 34);
        std::cout << b;
        b.up();
        std::cout << b;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    return 0;
}