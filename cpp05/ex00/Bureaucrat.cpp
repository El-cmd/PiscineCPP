#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Doc"), grade(150)
{
    std::cout << "Default Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(Bureaucrat &other)
{
    
}

Bureaucrat::Bureaucrat(std::string n, int g): name(n), grade(g)
{
    if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    if (g > 150)
        throw Bureaucrat::GradeTooLowException();
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

void Bureaucrat::down()
{
    if (this->grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void Bureaucrat::up()
{
    if (this->grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (out);
}
