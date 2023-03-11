#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Doc"), grade(1)
{
    std::cout << "Default Bureaucrat constructor called\n";
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

//ACCESSEUR
int Bureaucrat::getGrade()
{
    return (this->grade);
}

std::string Bureaucrat::getName()
{
    return(this->name);
}

//CHANGE GRADE
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

//SIGN FORM
void Bureaucrat::signForm(Form &f)
{
    if (f.getGradeToSign() < this->grade)
        std::cout << this->name << " cannot sign " << f.getName() << " because his grade is too low\n";
    else if (f.getIsSigned())
        std::cout << this->name << " cannot sign " << f.getName() << " because the form is already signed\n";
    else
    {
        f.beSigned(*this);
        std::cout << this->name << " signs " << f.getName() << std::endl;
    }
}

//SURCHARGE OPERATEUR
std::ostream &operator<<(std::ostream &out, Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (out);
}
