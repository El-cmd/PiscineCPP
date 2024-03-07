#include "PresidentialPardonForm.hpp"

/*---------------coplian form-----------------*/

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardonForm created with default target" << std::endl;
}

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

int PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
	{
        std::cout << executor.getName() << " cannot execute " << this->getName() << " because his not signed\n";
		return 0;
	}
    else if (executor.getGrade() > this->getGradeToExecute())
	{
        std::cout << executor.getName() << " cannot execute " << this->getName() << " because his _grade is too low\n";
		return 0;
	}
	else
		std::cout << this->getTarget() << " Has been pardoned by Zaphod Beeblebrox" << std::endl;
	return 1;
}