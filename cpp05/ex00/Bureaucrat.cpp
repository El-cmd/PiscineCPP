#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Doc"), grade(1)
{
    std::cout << "Default Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(std::string n, int g): name(n), grade(g)
{
    std::cout << "Surcharge constructor called\n";
}
Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Bureaucrat destructor called\n";
}

int Bureaucrat::getGrade()
{
    return (this->grade);
}

std::string Bureaucrat::getName()
{
    return(this->name);
}

const char *Bureaucrat::GradeTooHighException()
{
    return ("Grade is too high\n");
}
const char *Bureaucrat::GradeTooLowException()
{
    return ("Grade is too low\n");
}

void Bureaucrat::down()
{
    if (this->grade > 150)
    throw ;
    this->grade++;
}

void Bureaucrat::up()
{
    this->grade--;
}
