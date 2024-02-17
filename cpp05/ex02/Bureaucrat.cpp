#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Doc"), _grade(1)
{
    std::cout << "Default Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(std::string n, int g): _name(n), _grade(g)
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
int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::string Bureaucrat::getName() const
{
    return(this->_name);
}

//CHANGE GRADE
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

//SIGN FORM
void Bureaucrat::signForm(Form &f)
{
    if (f.getGradeToSign() < this->_grade)
        std::cout << this->_name << " cannot sign " << f.getName() << " because his _grade is too low\n";
    else if (f.getIsSigned())
        std::cout << this->_name << " cannot sign " << f.getName() << " because the form is already signed\n";
    else
    {
        f.beSigned(*this);
        std::cout << this->_name << " signs " << f.getName() << std::endl;
    }
}

//SURCHARGE OPERATEUR
std::ostream &operator<<(std::ostream &out, Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat _grade " << b.getGrade() << std::endl;
    return (out);
}

//EXECUTION DES FORMULAIRES
void Bureaucrat::executeForm(Form const & form)
{
    if (form.getIsSigned() == false)
        std::cout << this->_name << " cannot execute " << form.getName() << " because the form is not signed\n";
    else if (this->_grade > form.getGradeToExecute())
        std::cout << this->_name << " cannot execute " << form.getName() << " because his _grade is too low\n";
    else
        form.execute(*this);

}