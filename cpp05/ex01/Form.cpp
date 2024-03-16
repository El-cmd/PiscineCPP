#include "Form.hpp"

Form::Form(): _name("Doc"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
	std::cout << "Default Form constructor called\n";
}

Form::Form(std::string n, int gts, int gte): _name(n), isSigned(false), gradeToSign(gts), gradeToExecute(gte)
{
	if (gts < 1 || gte < 1)
		throw Form::GradeTooHighException();
	else if (gts > 150 || gte > 150)
		throw Form::GradeTooLowException();
	std::cout << "Surcharge Form constructor called\n";
}

Form::Form(Form const &other): _name(other._name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	if (other.gradeToExecute < 1 || other.gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (other.gradeToExecute > 150 || other.gradeToSign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Copy Form constructor called\n";
}

Form &Form::operator=(Form const &other)
{
	this->isSigned = other.isSigned;
	return *this;
}

Form::~Form()
{
	std::cout << "Default Form destructor called\n";
}

//ACCESSEUR
const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

void Form::beSigned(Bureaucrat &v)
{
	if (this->getIsSigned())
        std::cout << v.getName() << " cannot sign " << this->getName() << " because his already sign\n";
    else if (this->getGradeToSign() < v.getGrade())
        std::cout << v.getName() << " cannot sign " << this->getName() << " because his _grade is too low\n";
	else
	{
		this->isSigned = true;
		std::cout << v.getName() << " signs " << this->getName() << std::endl;
	}
}

//OPERATEUR DE SURCHARGE
std::ostream &operator<<(std::ostream &out, Form &f)
{
	out << f.getName() << ", form grade to sign " << f.getGradeToSign() << ", form grade to execute " << f.getGradeToExecute() << std::endl;
	return (out);
}