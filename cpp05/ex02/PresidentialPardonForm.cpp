#include "PresidentialPardonForm.hpp"

/*---------------coplian form-----------------*/

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other): AForm(other)
{
	*this = other;
	std::cout << "PresidentialPardonForm copied" << std::endl;	
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	this->_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

/*----------------------Getter-------------------*/

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

/*--------------Exec Fonction---------------*/

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->_gradeToExecute)
		std::cout << getTarget() << " Has been pardoned by Zaphod Beeblebrox" << std::endl;
}
