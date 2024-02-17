#include "Bureaucrat.hpp"
int main(void) 
{
    try 
    {
        Form form1("Player Contract", 150, 150);
        Bureaucrat bCrat1("Richarlison", 1);
        form1.beSigned(bCrat1);
        std::cout << "Welcome to the Club" << std::endl;
        bCrat1.up();
    }
    catch (std::exception &e) 
    {
        std::cout << "About to print the exception" << std::endl;
        std::cout << e.what() << std::endl;
    }
  
    std::cout  << "<<<<<<<<<<<<>>>>>>>>>>>" << std::endl;
    try 
    {
        Form form1("Drivers License", 1, 1);
        std::cout << form1;
        Bureaucrat bCrat1("Caitlyn Jenner", 150);
        form1.beSigned(bCrat1);
    }
    catch (std::exception &e) 
    {
        std::cout << "About to print the exception" << std::endl;
        std::cout << e.what() << std::endl;
    }

}