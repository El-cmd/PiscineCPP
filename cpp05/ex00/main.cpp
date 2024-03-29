#include "Bureaucrat.hpp"

int main(void) 
{
    //Good
	try 
	{
        Bureaucrat bureaucrat("bob", 2);
        std::cout << bureaucrat << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) 
	{
        std::cerr << "TooHighException" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) 
	{
        std::cerr << "TooLowException" << std::endl;
    }

    try 
	{
        Bureaucrat bureaucrat1("bob", 1);
        bureaucrat1.down();
        std::cout << bureaucrat1 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) 
	{
        std::cerr << "TooHighException" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) 
	{
        std::cerr << "TooLowException" << std::endl;
    }

    try 
	{
        Bureaucrat bureaucrat2("bob", 150);
        bureaucrat2.up();
        std::cout << bureaucrat2 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) 
	{
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) 
	{
        std::cerr << e.what() << std::endl;
    }
}