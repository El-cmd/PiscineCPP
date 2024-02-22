#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Doc"), _grade(150)
{
    std::cout << "Default Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const &other): _name(other._name), _grade(other._grade)
{
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Copy Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(std::string n, int g): _name(n), _grade(g)
{
    if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    if (g > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Surcharge constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    this->_grade = other.getGrade();
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();   
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Bureaucrat destructor called\n";
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

const std::string Bureaucrat::getName() const
{
    return(this->_name);
}

void Bureaucrat::down()
{
    if (this->_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::up()
{
    if (this->_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat _grade " << b.getGrade() << std::endl;
    return (out);
}
