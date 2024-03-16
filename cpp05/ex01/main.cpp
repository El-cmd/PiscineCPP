#include "Bureaucrat.hpp"
int main(void) 
{
    try 
    {
        Form form1("Player Contract", 150, 150);
        Bureaucrat bCrat1("Richarlison", 1);
        bCrat1.signForm(form1);
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
        bCrat1.signForm(form1);
        while (bCrat1.getGrade() > 1)
            bCrat1.up();
        bCrat1.signForm(form1);
    }
    catch (std::exception &e) 
    {
        std::cout << "About to print the exception" << std::endl;
        std::cout << e.what() << std::endl;
    }

}