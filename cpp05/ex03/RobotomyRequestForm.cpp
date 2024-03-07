#include "RobotomyRequestForm.hpp"

/*---------------coplian form-----------------*/

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequestForm created with default target" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other): AForm(other)
{
	*this = other;
	std::cout << "RobotomyRequestForm copied" << std::endl;	
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm&other)
{
	this->_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

/*----------------------Getter-------------------*/

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

/*--------------Exec Fonction---------------*/

int RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false || executor.getGrade() > this->getGradeToExecute())
	{
        std::cout << "Robotomy Failed" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "BRRRRR BRRRR BRRRR" << std::endl;
		std::cout << this->getTarget() << " has been robotomized successfully 50% of the time." << std::endl;
	}
	return 1;
}