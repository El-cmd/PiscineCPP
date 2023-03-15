#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string t): Form("RobotomyRequestForm", 72, 45)
{
	this->target = t;
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}
