#include "Form.hpp"

Form::Form(): _name("Doc"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
	std::cout << "Default Form constructor called\n";
}

Form::Form(std::string n, int gts, int gte): _name(n), isSigned(false), gradeToSign(gts), gradeToExecute(gte)
{
	if (gts < 1 || gte < 1)
		throw Form::GradeTooHighException();
	std::cout << "Surcharge Form constructor called\n";
}

Form::Form(Form const &other): _name(other._name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	if (other.gradeToExecute < 1 || other.gradeToSign < 1)
		throw Form::GradeTooHighException();
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
std::string Form::getName()
{
	return (this->_name);
}

bool Form::getIsSigned()
{
	return (this->isSigned);
}

int Form::getGradeToSign()
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute()
{
	return (this->gradeToExecute);
}

//CHANGE LE LE STATUE DE LA FONCTION
void Form::beSigned(Bureaucrat &v)
{
	if (v.getGrade() > getGradeToSign())
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

//OPERATEUR DE SURCHARGE
std::ostream &operator<<(std::ostream &out, Form &f)
{
	out << f.getName() << ", form grade to sign " << f.getGradeToSign() << ", form grade to execute " << f.getGradeToExecute() << std::endl;
	return (out);
}