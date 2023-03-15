#include "Form.hpp"

Form::Form(): name("Doc"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
	std::cout << "Default Form constructor called\n";
}

Form::Form(std::string n, int gts, int gte): name(n), isSigned(false), gradeToSign(gts), gradeToExecute(gte)
{
	if (gts < 1 || gte < 1)
		throw Form::GradeTooHighException();
	std::cout << "Surcharge Form constructor called\n";
}

Form::~Form()
{
	std::cout << "Default Form destructor called\n";
}

//ACCESSEUR
std::string Form::getName() const
{
	return (this->name);
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
	out << f.getName() << ", form grade to sign " << f.getGradeToSign() << ", form grade to execute " << f.getGradeToExecute();
	return (out);
}

//EXECUTION DES FORMULAIRES

void Form::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw Form::GradeTooLowException();
	if (getIsSigned() == false)
		throw Form::GradeTooLowException();
}