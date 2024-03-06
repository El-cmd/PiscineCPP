#include "AForm.hpp"

AForm::AForm(): _name("Doc"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << "Default AForm constructor called\n";
}

AForm::AForm(std::string n, int gts, int gte): _name(n), _isSigned(false), _gradeToSign(gts), _gradeToExecute(gte)
{
	std::cout << "Surcharge AForm constructor called\n";
}

AForm::AForm(AForm const &other): _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy AForm constructor called\n";
}

AForm &AForm::operator=(AForm const &other)
{
	this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{
	std::cout << "Default AForm destructor called\n";
}

//ACCESSEUR
const std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}


//EXEC
void AForm::beSigned(Bureaucrat &v)
{
	if (v.getGrade() <= this->_gradeToSign)
        this->_isSigned = true;
}

//OPERATEUR DE SURCHARGE
std::ostream &operator<<(std::ostream &out, AForm &f)
{
	out << f.getName() << ", AForm grade to sign " << f.getGradeToSign() << ", AForm grade to execute " << f.getGradeToExecute() << std::endl;
	return (out);
}