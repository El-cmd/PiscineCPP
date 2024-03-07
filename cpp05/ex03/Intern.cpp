#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern has been created" << std::endl;
}

Intern::Intern(Intern & other)
{
    std::cout << "Intern copy has been created" << std::endl;
    *this = other;
}

Intern &Intern::operator=(Intern &other)
{
    if (this != &other)
    {

    }
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern has been Destroy" << std::endl;
}

AForm *PPF(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *RRF(std::string target)
{
    return new RobotomyRequestForm(target); 
}

AForm *SCF(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string const &one, std::string two)
{
    typedef AForm *(*functPtr)(std::string two);
    std::string str[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    functPtr tab[3] = {&PPF, &RRF, &SCF};
    int i = 0;
    while (i < 3)
    {
        if (str[i] == one)
        {
            std::cout << "Intern creates " << one << std::endl;
            return (tab[i])(two);
        }   
        i++;
    }
    throw Intern::ErrInput();
    return NULL;
}

