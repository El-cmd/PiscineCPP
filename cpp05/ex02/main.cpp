#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat  *bureaucrat = new Bureaucrat("Bureaucrat", 2);
        AForm        *form = new PresidentialPardonForm("Target");
        bureaucrat->signForm(*form);
        bureaucrat->executeForm(*form);
        delete bureaucrat;
        delete form;

        std::cout << "-------------" << std::endl;

        Bureaucrat  *bureaucrat2 = new Bureaucrat("Bureaucrat2", 45);
        AForm        *form2 = new RobotomyRequestForm("Target2");
        bureaucrat->signForm(*form2);
        bureaucrat->executeForm(*form2);
        delete bureaucrat2;
        delete form2;

        std::cout << "-------------" << std::endl;

        Bureaucrat *bureaucrat3 = new Bureaucrat("Bureaucrat3", 130);
        AForm        *form3 = new ShrubberyCreationForm("Target3");
        bureaucrat->signForm(*form3);
        bureaucrat->executeForm(*form3);
        delete bureaucrat3;
        delete form3;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    
    return 0;
}