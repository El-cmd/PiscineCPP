#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
         Bureaucrat  *bureaucrat = new Bureaucrat("Bureaucrat", 45);
         AForm        *form = new PresidentialPardonForm("Form");
         bureaucrat->signForm(*form);
         bureaucrat->executeForm(*form);
         delete bureaucrat;
         delete form;
         
        Bureaucrat  *bureaucrat2 = new Bureaucrat("Bureaucrat", 45);
        AForm        *form2 = new RobotomyRequestForm("Form");
        bureaucrat->signForm(*form);
         bureaucrat->executeForm(*form);
         delete bureaucrat2;
         delete form2;
        
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    
    return 0;
}